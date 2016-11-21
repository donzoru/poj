#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int M = 100005;
int dp[M],v[M],w[M];
int a[1005],b[1005];
int main()
{
    int c,n,num,sum;
    while(scanf("%d%d",&c,&n)!=EOF)
    {
        num = sum = 0;
        for(int i=0;i<n;++i){
            scanf("%d%d",a+i,b+i);
            sum += a[i];
        }
        for(int i=0;i<n;++i){
            if(a[i]==0) continue;
            int k = (int)(log2(a[i]+1))-1;
            for(int j=0;j<=k;++j){
                int kk = (int)pow(2.0,j);
                w[num] = kk*b[i];
                v[num++] = kk*b[i];
            }
            k = (int)pow(2.0,k+1)-1;
            if(k!=a[i]){
                k = a[i]-k;
                w[num] = k*b[i];
                v[num++] = k*b[i];
            }
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<num;++i)
            for(int j=c;j>=w[i];--j)
                dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        printf("%d\n",dp[c]);
    }
    return 0;
}
