#include<cstdio>
#include<cstring>
#include<algorithm>
#define lowbit(i) i&-i
using namespace std;
const int M = 1030;
int a[M][M];
int n;
void upd(int x,int y,int d)
{
    for(int i=x;i<=n;i+=lowbit(i))
        for(int j=y;j<=n;j+=lowbit(j))
            a[i][j] += d;
}
int sum(int x,int y)
{
    int res = 0;
    for(int i=x;i>0;i-=lowbit(i))
        for(int j=y;j>0;j-=lowbit(j))
            res += a[i][j];
    return res;
}
int main()
{
    int s;
    int x1,y1,x2,y2,d;
    while(scanf("%d%d",&s,&n)!=EOF){
        memset(a,0,sizeof(a));
        while(scanf("%d",&s) && s!=3){
            if(s==1){
                scanf("%d%d%d",&x1,&y1,&d);
                upd(++x1,++y1,d);
            }else{
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                ++x1,++y1,++x2,++y2;
                int ans = sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
