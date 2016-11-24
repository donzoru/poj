#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int M = 550;
const int INF = 0x3f3f3f3f;
struct edge{
    int t,w,n;
}edg[M*M];
int dfn[M],low[M];
int col[M],h[M];
bool vis[M];
int dia[M][M],dis[M];
int num,t,n;
stack<int> ss;
void tarjan(int k)
{
    dfn[k] = low[k] = ++t;
    vis[k] = 1;
    ss.push(k);
    for(int i=h[k];i!=-1;i=edg[i].n){
        int v = edg[i].t;
        if(dfn[v]==-1){
            tarjan(v);
            low[k] = min(low[k],low[v]);
        }else if(vis[v]) low[k] = min(low[k],dfn[v]);
    }
    if(dfn[k] == low[k]){
        ++num;
        for(int v;;){
            v = ss.top();
            ss.pop();
            vis[v] = 0;
            col[v] = num;
            if(v==k) break;
        }
    }
}
void init()
{
    num = t = 0;
    for(int i=0;i<M;++i){
        dfn[i] = h[i] = -1;
        vis[i] = 0;
        col[i] = low[i] = 0;
    }
    memset(dia,0x3f,sizeof(dia));
    while(!ss.empty()) ss.pop();
}
void dijkstra(int s,int e)
{
    for(int i=1;i<=num;++i){
        vis[i] = 0;
        dis[i] = dia[s][i];
    }
    vis[s] = 1;
    int mini,k;
    for(;;){
        mini = INF;
        for(int j=1;j<=num;++j)
            if(!vis[j] && dis[j]<mini)
                mini = dis[j],k = j;
        if(mini==INF) break;
        vis[k] = 1;
        for(int j=1;j<=num;++j)
            if(dia[k][j]!=INF)
                dis[j] = min(dis[j],dis[k]+dia[k][j]);
    }
}
int main()
{
    int m;
    bool flag =0;
    while(scanf("%d",&n) && n)
    {
        scanf("%d",&m);
        if(flag) puts("");
        flag = 1;
        init();
        int x,y,w;
        for(int i=0;i<m;++i){
            scanf("%d%d%d",&x,&y,&w);
            edg[i].t = y;
            edg[i].w = w;
            edg[i].n = h[x];
            h[x] = i;
        }
        for(int i=1;i<=n;++i)
            if(dfn[i]==-1)
                tarjan(i);
        for(int i=1;i<=n;++i){
            x = col[i];
            for(int j=h[i];j!=-1;j=edg[j].n){
                y = col[edg[j].t];
                if(x!=y) dia[x][y] = min(dia[x][y],edg[j].w);
            }
        }
        scanf("%d",&m);
        while(m--){
            scanf("%d%d",&x,&y);
            x = col[x];
            y = col[y];
            if(x==y) {
                printf("0\n");
                continue;
            }
            dijkstra(x,num);
            w = dis[y];
            if(w!=INF) printf("%d\n",w);
            else printf("Nao e possivel entregar a carta\n");
        }
    }
    return 0;
}
