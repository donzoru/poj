#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int M = 20010;
const int INF = 0x3f3f3f3f;
struct edge{
    int u,v,ca,f,co,n;
    edge(){}
    edge(int u,int v,int ca,int f,int co,int n)
    :u(u),v(v),ca(ca),f(f),co(co),n(n){}
}edg[M];
struct ifo{
    int s,e,w;
}arr[M];
int H[100010];
int d[M],p[M],a[M];
int head[M];
bool v[M];
int n,k,cnt;
int s,e;
void add(int u,int v,int ca,int co)
{
    edg[cnt]=edge(u,v,ca,0,co,head[u]);
    head[u]=cnt++;
    edg[cnt]=edge(v,u,0,0,-co,head[v]);
    head[v]=cnt++;
}
bool spfa(int s,int e,int &flow,int &cost)
{
    memset(d,0x3f,sizeof(d));
    memset(p,-1,sizeof(p));
    memset(v,false,sizeof(v));
    queue<int> q;
    d[s]=0;
    a[s]=INF;
    v[s]=true;
    q.push(s);
    while(q.size()){
        int x=q.front(); q.pop();
        v[x]=false;
        for(int i=head[x];i!=-1;i=edg[i].n){
            if(edg[i].ca > edg[i].f && d[edg[i].v]>d[x]+edg[i].co){
                d[edg[i].v]=d[x]+edg[i].co;
                p[edg[i].v]=i;
                a[edg[i].v]=min(a[x],edg[i].ca-edg[i].f);
                if(v[edg[i].v]==false){
                    v[edg[i].v]=true;
                    q.push(edg[i].v);
                }
            }
        }
    }
    if(d[e]==INF) return false;
    flow+=a[e];
    cost+=d[e]*a[e];
    for(int i=e;i!=s;i=edg[p[i]].u){
        edg[p[i]].f+=a[e];
        edg[p[i]^1].f-=a[e];
    }
    return true;
}
int MinMax(int s,int e)
{
    int f=0,c=0;
    while(spfa(s,e,f,c));
    return c;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        memset(H,0,sizeof(H));
        int a,b,c;
        for(int i=0;i<n;++i){
            scanf("%d%d%d",&arr[i].s,&arr[i].e,&arr[i].w);
            H[arr[i].s]=H[arr[i].e]=1;
        }
        a=1;
        for(int i=0;i<100010;++i)
            if(H[i]) H[i]=a++;
        for(int i=0;i<n;++i){
            arr[i].s=H[arr[i].s];
            arr[i].e=H[arr[i].e];
        }
        s=0; e=a+1;
        memset(head,-1,sizeof(head));
        cnt=0;
        for(int i=0;i<e;++i)
            add(i,i+1,k,0);
        for(int i=0;i<n;++i)
            add(arr[i].s,arr[i].e,1,-arr[i].w);
        printf("%d\n",-MinMax(s,e));
    }
    return 0;
}
/*
4

3 1
1 2 2
2 3 4
3 4 8

3 1
1 3 2
2 3 4
3 4 8

3 1
1 100000 100000
1 2 3
100 200 300

3 2
1 100000 100000
1 150 301
100 200 300
*/
