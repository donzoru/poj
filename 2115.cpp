#include<cstdio>
typedef long long ll;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0){
        x = 1;
        y = 0;
        return  a;
    }
    ll r = exgcd(b,a%b,x,y);
    ll t = x;
    x = y;
    y = t - a/b*y;
    return r;
}
int main()
{
    ll a,b,c,x,y,k;
    while(scanf("%lld%lld%lld%lld",&a,&b,&c,&k) && k){
        k = (1LL<<k);
        b = (b-a+k)%k;
        ll g = exgcd(c,k,x,y);
        if(b%g)
            puts("FOREVER");
        else {
            x *= b/g;
            x = (x%k+k)%(k/g);
            printf("%lld\n",x);
        }
    }
    return 0;
}
/*
3 3 2 16
3 7 2 16
7 3 2 16
3 4 2 16
0 0 0 0
*/
