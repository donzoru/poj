#include<cstdio>
#include<cstring>
#include<algorithm>
#define lowbit(i) i&-i
#define M 1005
int a[M][M];
int n;
int sum(int x,int y)
{
    int res = 0;
    for(int i=x;i>0;i-=lowbit(i))
        for(int j=y;j>0;j-=lowbit(j))
            res += a[i][j];
    return res;
}
void upd(int x,int y)
{
    for(int i=x;i<=n;i+=lowbit(i))
        for(int j=y;j<=n;j+=lowbit(j))
            ++a[i][j];
}
int main()
{
    int t,q;
    scanf("%d",&t);
    int x1,y1,x2,y2;
    char c;
    while(t--){
        scanf("%d%d",&n,&q);
        memset(a,0,sizeof(a));
        while(q--){
            getchar();
            scanf("%c",&c);
            getchar();
            if(c=='C'){
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                upd(x1,y1);
                upd(x1,y2+1);
                upd(x2+1,y1);
                upd(x2+1,y2+1);
            }else{
                scanf("%d%d",&x1,&y1);
                printf("%d\n",sum(x1,y1)%2);
            }
        }
        puts("");
    }
    return 0;
}
