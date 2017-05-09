#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int M = 250;
struct edge{
    int f,t,n;
    ll w;
}edg[M*M*2];
ll g[M][M];
int res[M*100],vol[M*100];
int d[M*5],head[M*5];
int n,p,cnt;
int s,e;
void add(int f,int t,ll w)
{
    edg[cnt].f=f; edg[cnt].t=t;
    edg[cnt].w=w; edg[cnt].n=head[f];
    head[f]=cnt++;
    edg[cnt].f=t; edg[cnt].t=f;
    edg[cnt].w=0; edg[cnt].n=head[t];
    head[t]=cnt++;
}
bool bfs()
{
    memset(d,-1,sizeof(d));
    queue<int> q;
    d[s]=0;
    q.push(s);
    while(q.size()){
        int x=q.front(); q.pop();
        for(int i=head[x];i!=-1;i=edg[i].n)
            if(edg[i].w && d[edg[i].t]==-1)
                d[edg[i].t]=d[x]+1,q.push(edg[i].t);
    }
    return d[e]!=-1;
}
ll dfs(int u,ll b)
{
    if(u==e) return b;
    ll dt=b;
    for(int i=head[u];i!=-1;i=edg[i].n){
        if(edg[i].w && d[edg[i].t]==d[u]+1){
            ll f=dfs(edg[i].t,min(dt,edg[i].w));
            edg[i].w-=f;
            edg[i^1].w+=f;
            dt-=f;
            if(dt==0) return b;
        }
    }
    if(b-dt==0) d[u]=-1;
    return b-dt;
}
ll dinic()
{
    ll ans=0,f;
    while(bfs())
        while(f=dfs(s,INF))
            ans+=f;
    return ans;
}
void build(ll Max)
{
    memset(head,-1,sizeof(head));
    cnt=0;
    for(int i=1;i<=n;++i){
        add(s,i,res[i]);
        add(n+i,e,vol[i]);
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(g[i][j]<=Max) add(i,n+j,INF);
}
int main()
{
    ll a,b,c;
    while(scanf("%d%d",&n,&p)!=EOF){
        a=b=0;
        for(int i=1;i<=n;++i){
            scanf("%d%d",res+i,vol+i);
            a+=res[i];
            b+=vol[i];
        }
        ll sum=a;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(i==j) g[i][j]=0;
                else g[i][j]=INF;
        while(p--){
            scanf("%lld%lld%lld",&a,&b,&c);
            if(c<g[a][b]) g[a][b]=g[b][a]=c;
        }
        b=0;
        for(int k=1;k<=n;++k){
            for(int i=1;i<=n;++i){
                for(int j=1;j<=n;++j){
                    g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
                    if(g[i][j]!=INF) b=max(g[i][j],b);
                }
            }
        }
        ++b;
        a = 0;
        s = 0;
        e = 2*n+1;
        ll ans=-1;
        while(a<=b){
            c=a+b>>1;
            build(c);
            if(dinic()==sum){
                ans=c;
                b=c-1;
            }
            else a=c+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
3 4
7 2
0 4
2 6
1 2 40
3 2 70
2 3 90
1 3 120
6 6
10 0
0 3
0 7
3 0
0 2
0 1
1 2 120
5 2 80
5 1 20
5 6 30
6 1 110
4 3 30
10 9
1 0
0 0
0 0
0 1
0 1
0 1
0 1
0 1
0 1
0 1
2 1 10
3 1 4
4 3 2
5 3 5
6 2 11
7 5 1
8 6 7
9 4 1
10 2 10
*/
