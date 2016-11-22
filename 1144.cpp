#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int M = 102;
vector<int> edg[M];
int dfn[M],low[M];
bool vis[M],is[M];
int n,t;
void tarjan(int k,int f)
{
    dfn[k] = low[k] = ++t;
    vis[k] = 1;
    int cnt = 0;
    for(int i=0;i<edg[k].size();++i){
        int v = edg[k][i];
        if(!vis[v]){
            tarjan(v,k);
            ++cnt;
            low[k] = min(low[k],low[v]);
            if(k==1 && cnt>=2)
                is[k] = 1;
            if(k!=1 && low[v]>=dfn[k])
                is[k] = 1;
        }else if(vis[v] && v!=f) low[k] = min(low[k],dfn[v]);
    }
}
int main()
{
    while(scanf("%d",&n) && n)
    {
        t = 0;
        for(int i=0;i<=n;++i){
            edg[i].clear();
            dfn[i] = low[i] = 0;
            vis[i] = is[i] = 0;
        }
        int x,y;
        while(scanf("%d",&x) && x){
            while(getchar()!='\n'){
                scanf("%d",&y);
                edg[x].push_back(y);
                edg[y].push_back(x);
            }
        }
        tarjan(1,-1);
        x = 0;
        for(int i=1;i<=n;++i)
            if(is[i]) ++x;
        printf("%d\n",x);
    }
    return 0;
}
