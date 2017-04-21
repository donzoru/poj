#include<cstdio>
#include<cstdlib>
const int M = 1e6+3;
struct node{
    int k,p,r;
    int a[2];
    node() {}
    node(int k,int p,int r):k(k),p(p),r(r){
        a[0]=a[1]=0;
    }
    int cmp(int x){
        if(x==p) return -1;
        return x<p?0:1;
    }
}tre[M];
int cnt=1,rt=0;
void rot(int &r,int f)
{
    int k=tre[r].a[f^1];
    tre[r].a[f^1]=tre[k].a[f];
    tre[k].a[f]=r;
    r=k;
}
void ins(int &r,int k,int p)
{
    if(r==0)
        tre[r=cnt++]=node(k,p,rand());
    else{
        int f=tre[r].cmp(p);
        ins(tre[r].a[f],k,p);
        if(tre[tre[r].a[f]].r > tre[r].r)
            rot(r,f^1);
    }
}
void del(int &r,int p)
{
    int f=tre[r].cmp(p);
    if(f==-1){
        if(tre[r].a[0]==0) r=tre[r].a[1];
        else if(tre[r].a[1]==0) r=tre[r].a[0];
        else {
            int h= tre[tre[r].a[0]].r > tre[tre[r].a[1]].r;
            rot(r,h);
            del(tre[r].a[h],p);
        }
    }else{
        int h=tre[r].cmp(p);
        del(tre[r].a[h],p);
    }
}
inline int get(int r,int f)
{
    while(tre[r].a[f])
        r=tre[r].a[f];
    return r;
}
int main()
{
    int c,k,p;
    while(scanf("%d",&c) && c){
        switch(c){
            case 1:{
                scanf("%d%d",&k,&p);
                ins(rt,k,p);
                break;
            }
            case 2:{
                int k=get(rt,1);
                if(k){
                    printf("%d\n",tre[k].k);
                    del(rt,tre[k].p);
                }else puts("0");
                break;
            }
            case 3:{
                int k=get(rt,0);
                if(k){
                    printf("%d\n",tre[k].k);
                    del(rt,tre[k].p);
                }else puts("0");
                break;
            }
        }
    }
    return 0;
}
