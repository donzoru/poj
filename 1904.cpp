#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<iostream>
using namespace std;
const int M = 4003;
vector<int> g[M];
vector<int> ans[M];
int dfn[M],low[M],col[M];
bool vis[M];
int t,n,num;
stack<int> ss;
void init()
{
    for(int i=0;i<=2*n;++i){
        dfn[i] = -1;
        g[i].clear();
        ans[i].clear();
    }
    while(!ss.empty()) ss.pop();
    t = num = 0;
}
void tarjan(int k)
{
    dfn[k] = low[k] = ++t;
    vis[k] = 1;
    ss.push(k);
    for(int i=0;i<g[k].size();++i){
        int v = g[k][i];
        if(dfn[v]==-1){
            tarjan(v);
            low[k] = min(low[k],low[v]);
        }else if(vis[v]) low[k] = min(low[k],dfn[v]);
    }
    if(dfn[k] == low[k]){
        for(int v;;){
            v = ss.top();
            ss.pop();
            vis[v] = 0;
            col[v] =num;
            if(v==k) break;
        }
        ++num;
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        init();
        int a,x;
        for(int i=0;i<n;++i){
            scanf("%d",&a);
            while(a--){
                scanf("%d",&x);
                g[i+1].push_back(x+n);
            }
        }
        for(int i=0;i<n;++i){
            scanf("%d",&x);
            g[x+n].push_back(i+1);
        }
        for(int i=1;i<=2*n;++i)
            if(dfn[i]==-1)
                tarjan(i);
        for(int i=1;i<=n;++i){
            a = col[i];
            for(int j=0;j<g[i].size();++j){
                x = col[g[i][j]];
                if(a==x) ans[i].push_back(g[i][j]-n);
            }
            sort(ans[i].begin(),ans[i].end());
        }
        for(int i=1;i<=n;++i){
            printf("%d",ans[i].size());
            for(int j=0;j<ans[i].size();++j)
                printf(" %d",ans[i][j]);
            puts("");
        }
    }
    return 0;
}
