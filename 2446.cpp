#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
const int M = 1028;
vector<int>g[M];
bool vis[M];
int t[32][32];
int mat[M];
int n,m;
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
bool dfs(int k)
{
    for(int i=0;i<g[k].size();++i){
        int v = g[k][i];
        if(!vis[v]){
            vis[v] = 1;
            if(mat[v]==-1 || dfs(mat[v])){
                mat[v] = k;
                return 1;
            }
        }
    }
    return 0;
}
void init(){
    for(int i=0;i<M;++i){
        g[i].clear();
    }
}
int main()
{
    int p,x,y;
    while(scanf("%d%d%d",&n,&m,&p)!=EOF){
        init();
        int tt = n*m-p;
        while(p--){
            scanf("%d%d",&x,&y);
            t[y][x] = -1;
        }
        x = 1,y = 1;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(t[i][j]!=-1){
                    if((i+j) & 1) t[i][j] = x++;
                    else t[i][j] = y++;
                }
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(t[i][j]!=-1 && (( i+j )& 1)){
                    for(int k=0;k<4;++k){
                        int a = i+dx[k];
                        int b = j+dy[k];
                        if(a>0 && a<=n && b>0 && b<=m && t[a][b]!=-1){
                            g[t[i][j]].push_back(t[a][b]);
                        }
                    }
                }
            }
        }
        if((tt & 1) || x!=y) {
            puts("NO");
            continue;
        }
        memset(mat,-1,sizeof(mat));
        y = 0;
        for(int i=1;i<x;++i){
            memset(vis,0,sizeof(vis));
            if(dfs(i)) ++y;
        }
        if(y==tt/2) puts("YES");
        else puts("NO");
    }
    return 0;
}
