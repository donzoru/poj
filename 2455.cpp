#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<algorithm>
using namespace std;
const int M = 210;
const int INF = 2e9;
struct edge{
    int f,t,w,n;
    edge() {}
    edge(int f,int t,int w,int n):f(f),t(t),w(w),n(n) {}
}edg[2*M*M];
int F[M*M],T[M*M],W[M*M];
int head[M];
int d[M];
int n,p,t,cnt;
void add(int f,int t,int w)
{
    edg[cnt]=edge(f,t,w,head[f]);
    head[f]=cnt++;
    edg[cnt]=edge(t,f,w,head[t]);
    head[t]=cnt++;
}
bool bfs()
{
    memset(d,-1,sizeof(d));
    queue<int> q;
    d[1]=0;
    q.push(1);
    while(q.size()){
        int x=q.front(); q.pop();
        for(int i=head[x];i!=-1;i=edg[i].n){
            if(edg[i].w && d[edg[i].t]==-1)
                d[edg[i].t]=d[x]+1,q.push(edg[i].t);
        }
        if(d[n]!=-1) return true;
    }
    return d[n]!=-1;
}
int dfs(int u,int b)
{
    if(u==n) return b;
    int dt=b;
    for(int i=head[u];i!=-1;i=edg[i].n){
        if(edg[i].w>0 && d[edg[i].t]==d[u]+1){
            int f=dfs(edg[i].t,min(edg[i].w,dt));
            edg[i].w-=f;
            edg[i^1].w+=f;
            dt-=f;
        }
    }
    if(b-dt==0) d[u]=-1;
    return b-dt;
}
int dinic()
{
    int res=0,flow;
    while(bfs())
        while(flow=dfs(1,INF))
            res+=flow;
    return res;
}
void build(int Max)
{
    memset(head,-1,sizeof(head));
    cnt=0;
    for(int i=0;i<p;++i)
        if(W[i]<=Max) add(F[i],T[i],1);
}
int main()
{
    while(scanf("%d%d%d",&n,&p,&t)!=EOF){
        int l,r;
        l=INF,r=0;
        for(int i=0;i<p;++i){
            scanf("%d%d%d",F+i,T+i,W+i);
            l=min(l,W[i]);
            r=max(r,W[i]);
        }
        while(l<r){
            int m=l+r>>1;
            build(m);
            if(dinic()>=t) r=m;
            else l=m+1;
        }
        printf("%d\n",l);
    }
    return 0;
}
