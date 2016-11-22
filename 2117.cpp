#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int M = 10004;
vector<int> edg[M];
int dfn[M],low[M];
bool vis[M],is[M];
int n,t,dd;
int sum,num;
void tarjan(int k,int f)
{
    dfn[k] = low[k] = ++t;
    vis[k] = 1;
    int cnt = 0;
    for(int i=0;i<edg[k].size();++i)
    {
        int  v = edg[k][i];
        if(!vis[v]){
            tarjan(v,k);
            ++cnt;
            low[k] = min(low[k],low[v]);
            if(k!=dd && low[v]>=dfn[k]) is[k] =1;
            else if(k==dd && cnt>1) is[k] = 1;
        }else if(vis[v] && v!=f) low[k] = min(low[k],dfn[v]);
    }
}
void dfs(int k,int f)
{
    vis[k] = 1;
    for(int i=0;i<edg[k].size();++i){
        int v = edg[k][i];
        if(!vis[v]){
            if(k==f) ++sum;
            dfs(v,f);
        }
    }
}
void link(int k)
{
    vis[k] = 1;
    for(int i=0;i<edg[k].size();++i)
    {
        int v = edg[k][i];
        if(!vis[v])
            link(v);
    }
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m) &&m+n){
        if(m==0){
            printf("%d\n",n-1);
            continue;
        }
        for(int i=0;i<=n;++i){
            edg[i].clear();
            is[i] = vis[i] = 0;
        }
        int x,y;
        while(m--){
            scanf("%d%d",&x,&y);
            ++x,++y;
            edg[x].push_back(y);
            edg[y].push_back(x);
        }
        int lins = 0;
        for(int i=1;i<=n;++i)
            if(!vis[i])
                ++lins,link(i);
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;++i){
            if(!vis[i]){
                dd = i;
                tarjan(i,-1);
            }
        }
        x = lins;
        for(int i=1;i<=n;++i){
            if(is[i]){
                sum = 0;
                for(int j=1;j<=n;++j) vis[j] = 0;
                dfs(i,i);
                if(sum) x = max(x,sum+lins-1);
            }
        }
        printf("%d\n",x);
    }
    return 0;
}
