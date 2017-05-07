#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int M = 500;
int g[M][M];
int v[M],p[M];
int N,F,D,n;
void build()
{
    for(int i=0;i<F;++i)
        g[0][i+1]=1;
    for(int i=0;i<D;++i)
        g[F+2*N+1+i][n-1]=1;
    for(int i=0;i<N;++i)
        g[F+i+1][F+N+i+1]=1;
    int a,b,c;
    for(int i=0;i<N;++i){
        scanf("%d%d",&a,&b);
        while(a--){
            scanf("%d",&c);
            g[c][i+1+F]=1;
        }
        while(b--){
            scanf("%d",&c);
            g[F+N+1+i][F+2*N+c]=1;
        }
    }
}

queue<int> q;
int getMax(int s,int e)
{
    int res=0;
    for(;;){
        memset(v,0,sizeof(v));
        memset(p,-1,sizeof(p));
        while(!q.empty()) q.pop();
        q.push(s);
        v[s]=INF;
        p[s]=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            if(x==e) break;
            for(int i=0;i<n;++i){
                if(p[i]==-1 && g[x][i]>0){
                    v[i]=min(g[x][i],v[x]);
                    p[i]=x;
                    q.push(i);
                }
            }
            if(v[e]) break;
        }
        if(v[e]==0) break;
        for(int i=e;i!=s;i=p[i]){
            g[i][p[i]]+=v[e];
            g[p[i]][i]-=v[e];
        }
        res+=v[e];
    }
    return res;
}

int main()
{
    while(scanf("%d%d%d",&N,&F,&D)!=EOF){
        memset(g,0,sizeof(g));
        n=2*N+F+D+2;
        build();
        printf("%d\n",getMax(0,n-1));
    }
    return 0;
}
/*
4 3 3
2 2 1 2 3 1
2 2 2 3 1 2
2 2 1 3 1 2
2 1 1 3 3
*/
