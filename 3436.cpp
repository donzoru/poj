#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int M = 55;
const int INF = 0x3f3f3f3f;
int g[M][M],b[M][M];
int pre[M],v[M];
int ans[M][3];
struct Ma{
    int n;
    int in[11],ou[11];
}Ma[M];
int n,p;
void build()
{
    for(int i=1;i<=n;++i){
        scanf("%d",&Ma[i].n);
        for(int j=0;j<p;++j) scanf("%d",&Ma[i].in[j]);
        for(int j=0;j<p;++j) scanf("%d",&Ma[i].ou[j]);
    }
    for(int i=1;i<=n;++i){
        int si=1,ei=1;
        for(int j=0;j<p;++j) {
            if(Ma[i].in[j]==1) si=0;
            if(Ma[i].ou[j]==0) ei=0;
        }
        if(si) g[0][i]=Ma[i].n;
        if(ei) g[i][n+1]=Ma[i].n;
        for(int j=1;j<=n;++j){
            if(i==j) continue;
            si=1;
            for(int k=0;k<p;++k) if(Ma[i].ou[k]+Ma[j].in[k]==1) si=0;
            if(si) g[i][j]=min(Ma[i].n,Ma[j].n);
        }
    }
}
int getMax(int s,int e)
{
    int res=0;
    for(queue<int> q;;){
        while(!q.empty()) q.pop();
        memset(v,0,sizeof(v));
        memset(pre,-1,sizeof(pre));
        q.push(s);
        v[s]=INF;
        pre[s]=s;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int i=0;i<=e;++i){
                if(pre[i]==-1 && g[x][i]>0){
                    pre[i]=x;
                    v[i]=min(g[x][i],v[x]);
                    q.push(i);
                }
            }
            if(v[e]) break;
        }
        if(v[e]==0) break;
        for(int i=e;i!=s;i=pre[i]){
            g[pre[i]][i]-=v[e];
            g[i][pre[i]]+=v[e];
        }
        res+=v[e];
    }
    return res;
}
int main()
{
    while(scanf("%d%d",&p,&n)!=EOF){
        memset(g,0,sizeof(g));
        build();
        memcpy(b,g,sizeof(g));
        int maxx=getMax(0,n+1),cnt=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(b[i][j]>g[i][j]){
                    ans[cnt][0]=i;
                    ans[cnt][1]=j;
                    ans[cnt++][2]=b[i][j]-g[i][j];
                }
            }
        }
        printf("%d %d\n",maxx,cnt);
        for(int i=0;i<cnt;++i)
            printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
    }
    return 0;
}
/*
3 4
15  0 0 0  0 1 0
10  0 0 0  0 1 1
30  0 1 2  1 1 1
3   0 2 1  1 1 1
3 5
5   0 0 0  0 1 0
100 0 1 0  1 0 1
3   0 1 0  1 1 0
1   1 0 1  1 1 0
300 1 1 2  1 1 1
2 2
100  0 0  1 0
200  0 1  1 1
*/
