#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int M = 5005;
const int INF = 0x3f3f3f3f;
struct edge{
    int f,t,w,n;
    edge(){}
    edge(int f,int t,int w,int n):f(f),t(t),w(w),n(n){}
}edg[M*M];
int Min[M>>1],Max[M>>1];
int d[M],head[M];
int C,L;
int s,e,cnt;
void add(int f,int t,int w)
{
    edg[cnt]=edge(f,t,w,head[f]);
    head[f]=cnt++;
    edg[cnt]=edge(t,f,0,head[t]);
    head[t]=cnt++;
}
bool bfs()
{
    memset(d,-1,sizeof(d));
    d[s]=0;
    queue<int> q;
    q.push(s);
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
            int f=dfs(edg[i].t,min(dt,edg[i].w));
            edg[i].w-=f;
            edg[i^1].w+=f;
            dt-=f;
            if(dt==0) return b;
        }
    }
    if(b==dt) d[u]=-1;
    return b-dt;
}
int dinic()
{
    int res=0,f;
    while(bfs())
        while(f=dfs(s,INF))
            res+=f;
    return res;
}
void build()
{
    memset(head,-1,sizeof(head));
    cnt=0;
    int a,b;
    for(int i=1;i<=L;++i){
        scanf("%d%d",&a,&b);
        add(0,i,b);
        for(int j=0;j<C;++j)
            if(a>=Min[j] && a<=Max[j])
                add(i,L+j+1,1);
    }
    for(int i=1;i<=C;++i)
        add(L+i,L+C+1,1);
    s=0;
    e=L+C+1;
}
int main()
{
    while(~scanf("%d%d",&C,&L)){
        for(int i=0;i<C;++i) scanf("%d%d",Min+i,Max+i);
        build();
        printf("%d\n",dinic());
    }
    return 0;
}
/*
3 2
3 10
2 5
1 5
6 2
4 1
*/
