#include<cstdio>
#include<cstring>
const int M = 202;
bool dia[M][M],vis[M];
int mat[M];
int n,m;
bool dfs(int k)
{
    for(int i=1;i<=m;++i){
        if(dia[k][i] && !vis[i]){
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
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(dia,0,sizeof(dia));
        int a,b;
        for(int i=0;i<n;++i){
            scanf("%d",&a);
            while(a--){
                scanf("%d",&b);
                dia[i+1][b] = 1;
            }
        }
        memset(mat,255,sizeof(mat));
        a = 0;
        for(int i=1;i<=n;++i){
            memset(vis,0,sizeof(vis));
            if(dfs(i)) ++a;
        }
        printf("%d\n",a);
    }
    return 0;
}
