#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
const int M = 202;
typedef long long ll;
ll G[M][M];
ll v[M];
int p[M];
int n,m;
ll getMax(int s,int e)
{
    ll res=0;
    for(;;){
        memset(v,0,sizeof(v));
        memset(p,0,sizeof(p));
        queue<int> q;
        q.push(s);
        v[s]=INF;
        while(!q.empty()){
            int x=q.front(); q.pop();
            for(int i=1;i<=n;++i){
                if(v[i]==0 && G[x][i]>0){
                    v[i]=min(v[x],G[x][i]);
                    p[i]=x;
                    if(i==e) {
                        while(q.empty()) q.pop();
                        break;
                    }
                    q.push(i);
                }
            }
            if(v[e]) break;
        }
        if(v[e]==0) break;
        for(int i=e;i!=0;i=p[i]){
            G[i][p[i]]+=v[e];
            G[p[i]][i]-=v[e];
        }
        res+=v[e];
        //printf("%d\n",res);
    }
    return res;
}
int main()
{
    while(scanf("%d%d",&m,&n)!=EOF){
        memset(G,0,sizeof(G));
        int a,b;
        ll c;
        while(m--){
            scanf("%d%d%lld",&a,&b,&c);
            G[a][b]+=c;
        }
        printf("%lld\n",getMax(1,n));
    }
    return 0;
}
