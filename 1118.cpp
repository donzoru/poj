#include<cstdio>
int x[700],y[700];
int main()
{
    int n,ans;
    while(scanf("%d",&n) && n)
    {
        for(int i=0;i<n;++i)
            scanf("%d %d",x+i,y+i);
        ans = 2;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                int sum = 2;
                for(int k=j+1;k<n;++k){
                    if((x[j]-x[i])*(y[k]-y[j])==(y[j]-y[i])*(x[k]-x[j]))
                        ++sum;
                }
                if(sum>ans) ans = sum;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
