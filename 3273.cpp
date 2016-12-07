#include<cstdio>
#include<algorithm>
using namespace std;
const int M = 100005;
int a[M];
int n,m;
bool ok(int k)
{
    int cnt = 0,sum = 0;
    for(int i=0;i<n;++i){
        if(a[i]>k) return 0;
        sum += a[i];
        if(sum > k){
            ++cnt;
            sum = a[i];
        }
    }
    return cnt + 1 <= m;
}
int main()
{
    int sum;
    while(scanf("%d%d",&n,&m)!=EOF){
        sum = 0;
        for(int i=0;i<n;++i){
            scanf("%d",a+i);
            sum += a[i];
        }
        int l=*max_element(a,a+n),r=sum;
        while(l < r){
            int mid = l + r >> 1;
            if(ok(mid)) r = mid;
            else l = mid + 1;
        }
        printf("%d\n",l);
    }
    return 0;
}
//100 400 300 100 500 101 400
//0   0   1   1   2   3   4
//100 500 300 400 500 101 400
