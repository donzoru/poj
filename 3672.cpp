#include<cstdio>
const int M = 1e5+10;
int a[M],b[M];
int m,t,u,f,d;
int main()
{
    int sum,i;
    while(~scanf("%d%d%d%d%d",&m,&t,&u,&f,&d)){
        char c;
        for(i=0;i<t;++i){
            getchar();
            c=getchar();
            switch(c){
                case'u':a[i]=u;b[i]=d;break;
                case'f':a[i]=b[i]=f;break;
                case'd':a[i]=d;b[i]=u;break;
            }
        }
        sum=0;
        for(i=0;i<t;++i){
            sum+=a[i]+b[i];
            if(sum>m) break;
        }
        printf("%d\n",i);
    }
    return 0;
}
