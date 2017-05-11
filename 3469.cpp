#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int M = 2e4+10;
const int INF = 0x3f3f3f3f;
struct edge{
    int f,t,w,n;
    edge() {}
    edge(int f,int t,int w,int n)
    :f(f),t(t),w(w),n(n){}
}edg[M*30];
int head[M],d[M];
int n,m,cnt;
int s,e;
void add(int f,int t,int w,bool flag)
{
    edg[cnt]=edge(f,t,w,head[f]);
    head[f]=cnt++;
    edg[cnt]=edge(t,f,flag?w:0,head[t]);
    head[t]=cnt++;
}
bool bfs()
{
    memset(d,-1,sizeof(d));
    queue<int> q;
    q.push(s);
    d[s]=0;
    while(q.size()){
        int x=q.front(); q.pop();
        for(int i=head[x];i!=-1;i=edg[i].n){
            if(edg[i].w && d[edg[i].t]==-1)
                d[edg[i].t]=d[x]+1,q.push(edg[i].t);
        }
        if(d[e]!=-1) return true;
    }
    return d[e]!=-1;
}
int dfs(int u,int b)
{
    if(u==e) return b;
    int dt=b;
    for(int i=head[u];i!=-1;i=edg[i].n){
        if(edg[i].w && d[edg[i].t]==d[u]+1){
            int f=dfs(edg[i].t,min(edg[i].w,dt));
            edg[i].w-=f;
            edg[i^1].w+=f;
            dt-=f;
            if(dt==0) return b;
        }
    }
    if(b-dt==0) d[u]=-1;
    return b-dt;
}
int dinic()
{
    int ans=0,flow;
    while(bfs())
        while(flow=dfs(s,INF))
            ans+=flow;
    return ans;
}
void build()
{
    memset(head,-1,sizeof(head));
    cnt=0;
    s=0,e=n+1;
    int a,b,c;
    for(int i=1;i<=n;++i){
        scanf("%d%d",&a,&b);
        add(s,i,a,0);
        add(i,e,b,0);
    }
    while(m--){
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c,1);
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m)){
        build();
        printf("%d\n",dinic());
    }
    return 0;
}
/*
3 1
1 10
2 10
10 3
2 3 1000
*/
