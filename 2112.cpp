#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int m =  240;
const int INF = 0x3f3f3f3f;
int g[m][m],o[m][m];
int l[m];
int K,C,M,n;
bool bfs()
{
    memset(l,-1,sizeof(l));
    queue<int> q;
    q.push(0);
    l[0]=0;
    while(!q.empty()){
        int t=q.front();q.pop();
        for(int i=0;i<=n;++i){
            if(o[t][i]!=0 && l[i]==-1)
                l[i]=l[t]+1,q.push(i);
        }
    }
    return l[n]!=-1;
}
int dfs(int u,int big)
{
    if(u==n) return big;
    int d=big;
    for(int i=0;i<=n;++i){
        if(o[u][i]>0 && l[u]+1==l[i]){
            int flow = dfs(i,min(o[u][i],d));
            o[u][i]-=flow;
            o[i][u]+=flow;
            d-=flow;
        }
    }
    return big-d;
}

int dinic()
{
    int a,res=0;
    while(bfs())
        while(a=dfs(0,INF))
            res+=a;
    return res;
}

void build(int mini)
{
    memset(o,0,sizeof(o));
    for(int i=1;i<=K;++i)
        o[0][i]=M;
    for(int i=K+1;i<n;++i)
        o[i][n]=1;
    for(int i=1;i<=K;++i)
        for(int j=K+1;j<n;++j)
            if(g[i][j]<=mini)
                ++o[i][j];
}
int main()
{
    while(~scanf("%d%d%d",&K,&C,&M)){
        n=K+C+1;
        for(int i=1;i<n;++i)
            for(int j=1;j<n;++j)
                scanf("%d",&g[i][j]),g[i][j]+=(g[i][j]==0?INF:0);
        for(int k=1;k<n;++k)
            for(int i=1;i<n;++i)
                for(int j=1;j<n;++j)
                    g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
        int l=1,r=INF,mid;
        while(l<r){
            mid=l+r>>1;
            build(mid);
            if(dinic()==C) r=mid;
            else l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}
/*
2 3 2
0 3 2 1 1
3 0 3 2 0
2 3 0 1 0
1 2 1 0 2
1 0 0 2 0
*/
