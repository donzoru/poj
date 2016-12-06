#include<cstdio>
#include<cstring>
const int M = 202;
bool dia[M][M],fia[M][M],vis[M];
int mat[M];
int n,m;
bool dfs(int k)
{
    for(int i=1;i<=m;++i){
        if(fia[k][i] && !vis[i]){
            vis[i] = 1;
            if(mat[i]==-1 || dfs(mat[i])){
                mat[i] = k;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int p,t = 1;
    while(scanf("%d%d%d",&n,&m,&p) && n+m+p){
        memset(dia,0,sizeof(dia));
        memset(fia,0,sizeof(fia));
        int a,b;
        while(p--){
            scanf("%d%d",&a,&b);
            dia[a][b] = 1;
        }
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                fia[i][j] = !dia[i][j];
        memset(mat,255,sizeof(mat));
        a = 0;
        for(int i=1;i<=n;++i){
            memset(vis,0,sizeof(vis));
            if(dfs(i)) ++a;
        }
        printf("Case %d: %d\n",t++,n+m-a);
    }
    return 0;
}
