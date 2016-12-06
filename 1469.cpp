#include<cstdio>
#include<cstring>
const int M = 303;
bool dia[M][M],vis[M];
int mat[M];
int p,m;
bool dfs(int k)
{
    for(int i=1;i<=m;++i){
        if(dia[k][i] && !vis[i]){
            vis[i] = 1;
            if(mat[i]==-1 || dfs(mat[i])){
                mat[i] = k;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int t,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&p,&m);
        memset(dia,0,sizeof(dia));
        for(int i=0;i<p;++i){
            scanf("%d",&a);
            while(a--){
                scanf("%d",&b);
                dia[i+1][b] = 1;
            }
        }
        memset(mat,255,sizeof(mat));
        a = 0;
        for(int i=1;i<=p;++i){
            memset(vis,0,sizeof(vis));
            if(dfs(i)) ++a;
        }
        if(a==p) puts("YES");
        else puts("NO");
    }
    return 0;
}
