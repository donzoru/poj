#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int M = 10005;
int dp[M*4],v[M],w[M],a[M];
struct block{
    int h,a,c;
    bool operator <(const block & x) const {
        return a<x.a;
    }
}lis[405];
int main()
{
    int n,num;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;++i)
            scanf("%d%d%d",&lis[i].h,&lis[i].a,&lis[i].c);
        num = 0;
        sort(lis,lis+n);
        for(int i=0;i<n;++i)
        {
            int k = (int)log2(lis[i].c+1)-1;
            for(int j=0;j<=k;++j){
                int kk = (int)pow(2.0,j);
                v[num] = kk*lis[i].h;
                a[num] = lis[i].a;
                w[num++] = kk*lis[i].h;
            }
            k = (int)pow(2.0,k+1)-1;
            if(lis[i].c!=k){
                k = lis[i].c-k;
                v[num] = k*lis[i].h;
                a[num] = lis[i].a;
                w[num++] = k*lis[i].h;
            }
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<num;++i)
            for(int j=a[i];j>=w[i];--j)
                dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        int ans = 0;
        for(int i=0;i<M*4;++i)
            ans = max(ans,dp[i]);
        printf("%d\n",ans);
    }
    return 0;
}
