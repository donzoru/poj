#include<cstdio>
#include<cstdlib>
const int M = 3e4+5;
struct node{
    int k,r,s;
    int a[2];
    int cmp(int x){
       return x<k?0:1;
    }
    node(){}
    node(int k,int r,int s):k(k),r(r),s(s){
        a[0]=a[1]=0;
    }
}Tre[M];
int cnt=1,root=0;
int A[M];
void rot(int &x,int f)
{
    int y=Tre[x].a[f^1];
    Tre[x].s=Tre[x].s-Tre[y].s+Tre[Tre[y].a[f]].s;
    Tre[x].a[f^1]=Tre[y].a[f];
    Tre[y].s=Tre[y].s-Tre[Tre[y].a[f]].s+Tre[x].s;
    Tre[y].a[f]=x;
    x=y;
}
void ins(int &x,int k)
{
    if(x==0)
        Tre[x = cnt++] = node(k,rand(),1);
    else{
        ++Tre[x].s;
        int f=Tre[x].cmp(k);
        ins(Tre[x].a[f],k);
        if(Tre[Tre[x].a[f]].r > Tre[x].r)
            rot(x,f^1);
    }
}
int fin(int &x,int k)
{
    if(k==Tre[Tre[x].a[0]].s+1)
        return Tre[x].k;
    if(k>Tre[Tre[x].a[0]].s+1)
        return fin(Tre[x].a[1],k-Tre[Tre[x].a[0]].s-1);
    else
        return fin(Tre[x].a[0],k);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int s,e;
    for(int i=0;i<n;++i) scanf("%d",A+i);
    s=e=0;
    for(int i=0;i<m;++i){
        scanf("%d",&e);
        for(int j=s;j<e;++j)
            ins(root,A[j]);
        s=e;
        printf("%d\n",fin(root,i+1));
    }
    return 0;
}
