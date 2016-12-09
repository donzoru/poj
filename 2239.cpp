#include<cstdio>
#include<cstring>
const int M = 303;
bool dia[M][M],vis[M];
int mat[M];
int n,m;
bool dfs(int k)
{
    for(int i=1;i<85;++i){
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
    int a,b;
    while(scanf("%d",&n)!=EOF){
        memset(dia,0,sizeof(dia));
        for(int i=1;i<=n;++i){
            scanf("%d",&m);
            while(m--){
                scanf("%d%d",&a,&b);
                dia[i][(a-1)*12+b] = 1;
            }
        }
        memset(mat,-1,sizeof(mat));
        a = 0;
        for(int i=1;i<=n;++i){
            memset(vis,0,sizeof(vis));
            if(dfs(i)) ++a;
        }
        printf("%d\n",a);
    }
    return 0;
}
