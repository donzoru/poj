#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int M = 2e5+10;
#define lsh(x) x<<1
#define rsh(x) x<<1|1
int T[M<<2];
void build(int l,int r,int p)
{
    T[p]=r-l+1;
    if(l==r) return;
    int m=l+r>>1;
    build(l,m,lsh(p));
    build(m+1,r,rsh(p));
}
int que(int l,int r,int k,int p)
{
    if(l==r){
        T[p]=0;
        return l;
    }
    int m=l+r>>1;
    int res;
    if(k<=T[lsh(p)])
        res = que(l,m,k,lsh(p));
    else
        res = que(m+1,r,k-T[lsh(p)],rsh(p));
    T[p]=T[lsh(p)]+T[rsh(p)];
    return res;
}
int a[M],b[M];
int ans[M];
int main()
{
    int n;
    while(~scanf("%d",&n)){
        build(1,n,1);
        for(int i=0;i<n;++i)
            scanf("%d%d",a+i,b+i);
        for(int i=n-1;i>=0;--i){
            int t = que(1,n,a[i]+1,1);
            ans[t]=b[i];
        }
        for(int i=1;i<=n;++i)
            printf("%d%c",ans[i],i==n?'\n':' ');
    }
    return 0;
}
