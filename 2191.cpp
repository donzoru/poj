#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int times = 12;
vector<ll>ans;
ll gcd(ll a,ll b){ while(b) b^=a^=b^=a%=b; return a; }
ll Mul(ll a,ll b, ll m)
{
    a%=m;
    b%=m;
    ll res=0;
    while(b){
        if(b & 1) {
            res+=a;
            if(res>=m) res-=m;
        }
        a<<=1;
        if(a>=m) a-=m;
        b>>=1;
    }
    return res;
}
ll Pow(ll a,ll b,ll m)
{
    a%=m;
    ll res=1;
    while(b){
        if(b & 1) res=Mul(res,a,m);
        a=Mul(a,a,m);
        b>>=1;
    }
    return res;
}
bool ok(ll a,ll n)
{
    ll s=n-1;
    int j=0;
    while(!(s&1)){
        s>>=1;
        ++j;
    }
    ll x=Pow(a,s,n);
    if(x==1 || x==n-1) return false;
    while(j--){
        x=Mul(x,x,n);
        if(x==n-1) return false;
    }
    return true;
}
bool mr(ll n)
{
    if(n==2) return true;
    if(!(n&1) || n<2) return false;
    for(int i=0;i<times;++i){
        ll a=rand()%(n-1)+1;
        if(ok(a,n))
            return false;
    }
    return true;
}
ll pr(ll n,ll c)
{
    ll i=1,j=2;
    ll x=rand()%(n-1)+1;
    ll y=x;
    for(;;){
        ++i;
        x=(Mul(x,x,n)+c)%n;
        ll d=gcd(y-x,n);
        if(d>1 && d<n)
            return d;
        if(x==y)
            return n;
        if(i==j){
            y=x;
            j<<=1;
        }
    }
}
void src(ll n,ll c)
{
    if(n==1) return;
    if(mr(n)){
        ans.push_back(n);
        return;
    }
    ll p=n;
    while(p>=n) p=pr(p,c--);
    src(p,c);
    src(n/p,c);
}
ll prime[]={11,23,29,37,41,43,47,53,59};
int main()
{
    ll k;
    while(scanf("%lld",&k)!=EOF){
        for(int i=0;i<9 && k>=prime[i];++i){
            ll t=(1LL<<prime[i])-1;
            if(mr(t)) continue;
            else{
                ans.clear();
                src(t,rand()%(t-1)+1);
                sort(ans.begin(),ans.end());
                printf("%lld",ans[0]);
                for(int j=1;j<ans.size();++j)
                    printf(" * %lld",ans[j]);
                printf(" = %lld = ( 2 ^ %lld ) - 1\n",t,prime[i]);
            }
        }
    }
    return 0;
}
