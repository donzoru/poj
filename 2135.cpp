#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int M = 1e5+10;
struct edge{
    int u,v,ca,f,co,n;
    edge() {}
    edge(int u,int v,int ca,int f,int co,int n)
    :u(u),v(v),ca(ca),f(f),co(co),n(n) {}
}edg[M*2];
int head[M];
int p[M],d[M],a[M];
int inq[M];
int n,m,cnt;
void add(int f,int t,int ca,int co)
{
    edg[cnt]=edge(f,t,ca,0,co,head[f]);
    head[f]=cnt++;
    edg[cnt]=edge(t,f,0,0,-co,head[t]);
    head[t]=cnt++;
}
bool spfa(int s,int t,int &flow,int &cost)
{
    memset(d,0x3f,sizeof(d));
    memset(inq,0,sizeof(inq));
    memset(p,-1,sizeof(p));
    d[s]=0;
    inq[s]=1;
    a[s]=INF;
    queue<int> q;
    q.push(s);
    while(q.size()){
        int x=q.front(); q.pop();
        --inq[x];
        for(int i=head[x];i!=-1;i=edg[i].n){
            if(edg[i].ca>edg[i].f && d[edg[i].v]>d[x]+edg[i].co){
                d[edg[i].v]=d[x]+edg[i].co;
                p[edg[i].v]=i;
                a[edg[i].v]=min(a[x],edg[i].ca-edg[i].f);
                if(inq[edg[i].v]==0){
                    q.push(edg[i].v);
                    ++inq[edg[i].v];
                }
            }
        }
    }
    if(d[t]==INF) return false;
    flow+=a[t];
    cost+=d[t]*a[t];
    for(int i=t;i!=s;i=edg[p[i]].u){
        edg[p[i]].f+=a[t];
        edg[p[i]^1].f-=a[t];
    }
    return true;
}
int MinMax(int s,int t)
{
    int f=0,c=0;
    while(spfa(s,t,f,c));
    return c;
}
void build()
{
    memset(head,-1,sizeof(head));
    cnt=0;
    add(0,1,2,0);
    add(n,n+1,2,0);
    int x,y,z;
    while(m--){
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,1,z);
        add(y,x,1,z);
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m)){
        build();
        printf("%d\n",MinMax(0,n+1));
    }
    return 0;
}
/*
4 5
1 2 1
2 3 1
3 4 1
1 3 2
2 4 2
*/
