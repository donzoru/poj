#include<cstdio>
#include<cstring>
#include<cmath>
const int M = 105;
bool dia[M][M],vis[M];
int mat[M];
double xx[M][2],yy[M][2];
int n,m;
bool dfs(int k)
{
    for(int i=0;i<m;++i){
        if(!vis[i] && dia[k][i]){
            vis[i] = 1;
            if(mat[i]==-1 || dfs(mat[i])){
                mat[i] = k;
                return 1;
            }
        }
    }
    return 0;
}
double dis(double a,double b)
{
    return sqrt(a*a + b*b);
}
int main()
{
    double x,y,v,t;
    while(scanf("%d %d %lf %lf",&n,&m,&v,&t)!=EOF){
        memset(dia,0,sizeof(dia));
        for(int i=0;i<n;++i)
            scanf("%lf %lf",&xx[i][0],&xx[i][1]);
        for(int i=0;i<m;++i)
            scanf("%lf %lf",&yy[i][0],&yy[i][1]);
        v = v*t;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                x = xx[i][0] - yy[j][0];
                y = xx[i][1] - yy[j][1];
                if( v >= dis(x,y))
                    dia[i][j] = 1;
            }
        }
        memset(mat,-1,sizeof(mat));
        int ans = 0;
        for(int i=0;i<n;++i){
            memset(vis,0,sizeof(vis));
            if(dfs(i)) ++ans;
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
/*
2 2 5 10
1.0 1.0
2.0 2.0
100.0 100.0
20.0 20.0
*/
