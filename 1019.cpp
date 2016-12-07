#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int M = 52850;
int c[M],n[M];
long long s[M];
int len(int k)
{
    int res = 0;
    while(k){
        k/=10;
        ++res;
    }
    return res;
}
int main()
{
    c[0] = s[0] = 0;
    for(int i=1;i<M;++i) n[i] = len(i);
    for(int i=1;i<M;++i) c[i] = c[i-1] + n[i];
    for(int i=1;i<M;++i) s[i] = s[i-1] + c[i];
    int num,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&num);
        int u = lower_bound(s+1,s+M+1,num) - s - 1;//find the 1~n
        int pos = num - s[u];
        u = lower_bound(c+1,c+M+1,pos) - c - 1;//the number has the nth digit
        pos = pos - c[u];
        ++u;//the number
        pos = n[u] - pos + 1;//get the position from the back
        while( pos > 1 ){
            u /= 10;
            --pos;
        }
        printf("%d\n",u%10);
    }
    return 0;
}
