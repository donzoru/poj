#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int M = 240;
struct poi{
    int x,y;
    poi(){}
    poi(int x,int y):x(x),y(y){}
}H[M],P[M];
int nh,np;
struct edge{
    int u,v,ca,f,co,n;
    edge(){}
    edge(int u,int v,int ca,int fa,int co,int n)
    :u(u),v(v),ca(ca),f(f),co(co),n(n){}
}edg[M*M];
int p[M],d[M],a[M],inq[M];
int head[M];
int n,m,cnt;
void add(int u,int v,int ca,int co)
{
    edg[cnt]=edge(u,v,ca,0,co,head[u]);
    head[u]=cnt++;
    edg[cnt]=edge(v,u,0,0,-co,head[v]);
    head[v]=cnt++;
}
bool spfa(int s,int t,int &flow,int &cost)
{
    queue<int> q;
    memset(d,0x3f,sizeof(d));
    memset(inq,0,sizeof(inq));
    memset(p,-1,sizeof(p));
    d[s]=0;
    inq[s]=1;
    a[s]=INF;
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
                    ++inq[edg[i].v];
                    q.push(edg[i].v);
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
int MinCostMaxFlow(int s,int t)
{
    int f=0,c=0;
    while(spfa(s,t,f,c));
    return c;
}
int mhd(int i,int j)
{
    return abs(H[i].x-P[j].x)+abs(H[i].y-P[j].y);
}
void build()
{
    memset(head,-1,sizeof(head));
    cnt=0;
    for(int i=1;i<=np;++i)
        add(0,i,1,0);
    for(int i=1;i<=nh;++i)
        add(i+np,np+nh+1,1,0);
    for(int i=0;i<nh;++i)
        for(int j=0;j<np;++j)
            add(j+1,np+i+1,1,mhd(i,j));
}
int main()
{
    while(scanf("%d%d",&n,&m) && n+m){
        np=nh=0;
        char c;
        for(int i=0;i<n;++i){
            getchar();
            for(int j=0;j<m;++j){
                c=getchar();
                if(c=='H') H[nh++]=poi(i,j);
                else if(c=='m') P[np++]=poi(i,j);
            }
        }
        build();
        printf("%d\n",MinCostMaxFlow(0,1+np+nh));
    }
    return 0;
}
/*
2 2
.m
H.
5 5
HH..m
.....
.....
.....
mm..H
7 8
...H....
...H....
...H....
mmmHmmmm
...H....
...H....
...H....
0 0
*/
