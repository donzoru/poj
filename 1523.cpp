#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int M = 1002;
vector<int> edg[M];
int dfn[M],low[M];
bool vis[M],is[M];
int n,t,sum;
void init()
{
    for(int i=0;i<M;++i){
        edg[i].clear();
        vis[i] = is[i] = 0;
    }
    t = n = 0;
}
void dfs(int k,int f)
{
    dfn[k] = low[k] =++t;
    vis[k] = 1;
    int cnt = 0;
    for(int i=0;i<edg[k].size();++i){
        int v = edg[k][i];
        if(!vis[v]){
            dfs(v,k);
            ++cnt;
            low[k] = min(low[k],low[v]);
            if(k!=1 && low[v]>=dfn[k]) is[k] = 1;
            else if(k==1 && cnt>1) is[k] = 1;
        }else if(vis[v] && v!=f) low[k] = min(low[k],dfn[v]);
    }
}
void che(int k,int f)
{
    vis[k] = 1;
    for(int i=0;i<edg[k].size();++i){
        int v = edg[k][i];
        if(!vis[v]) {
            if(k==f) ++sum;
            che(v,f);
        }
    }
}
int main()
{
    int x,y,tt = 1;
    while(scanf("%d",&x) && x){
        init();
        while(x){
            scanf("%d",&y);
            edg[x].push_back(y);
            edg[y].push_back(x);
            n = max(n,max(x,y));
            scanf("%d",&x);
        }
        dfs(1,-1);
        x = 0;
        y = 0;
        printf("Network #%d\n",tt++);
        for(int i=1;i<=n;++i){
            if(is[i]){
                for(int j=1;j<=n;++j) vis[j] = 0;
                y = 1;
                sum = 0;
                che(i,i);
                if(sum)
                    printf("  SPF node %d leaves %d subnets\n",i,sum);
            }
        }
        if(y==0) printf("  No SPF nodes\n");
        puts("");
    }
    return 0;
}
