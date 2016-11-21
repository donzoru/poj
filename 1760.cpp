#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
    bool is;
    char s[105];
    node * next[128];
}nod[500005],*root;
int num,n;
char s[10005];
node * cre()
{
    node * p = &nod[num++];
    for(int i=0;i<128;++i)
        p->next[i] = NULL;
    p->is = NULL;
    return p;
}
char str[1005];
void ins()
{
    int k,n = 0;
    node * p = root;
    for(int i=0;s[i];++i)
    {
        if(s[i]=='\\'){
            p->is = 1;
            str[n] = 0;
            strcpy(p->s,str);
            k = n = 0;
        }
        else {
            k = s[i];
            str[n++] = s[i];
        }
        if(p->next[k]==NULL) p->next[k] = cre();
        p = p->next[k];
    }
    str[n] = 0;
    strcpy(p->s,str);
    p->is = 1;
}

void dfs(node * p,int k)
{
    if(p->is){
        for(int i=0;i<k;++i)
            putchar(' ');
        printf("%s\n",p->s);
        if(p->next[0]) dfs(p->next[0],k+1);
        for(int i=1;i<128;++i)
            if(p->next[i])
                dfs(p->next[i],k);
        return;
    }
    for(int i=0;i<128;++i)
        if(p->next[i])
            dfs(p->next[i],k);
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        num = 0;
        root = cre();
        for(int i=0;i<n;++i){
            scanf("%s",s);
            ins();
        }
        for(int i=0;i<128;++i)
            if(root->next[i])
                dfs(root->next[i],0);
    }
    return 0;
}
/*
void dfs(node * loc,int t,int k,int x)
{
    if(t==0){
        for(int i=0;i<128;++i)
            if(loc->next[i])
                dfs(loc->next[i],i,k,x);
        return;
    }
    //printf("%d\n",x);
    s[x] = (char)t;
    if(loc->is){
        s[x+1] = 0;
        for(int i=0;i<k;++i)
            putchar(' ');
        printf("%s\n",s);
        //memset(s,0,sizeof(s));
        //if(loc->next[0]) dfs(loc->next[0],0,k+1,0);
        for(int i=0;i<128;++i)
            if(loc->next[i])
                dfs(loc->next[i],i,k+1,0);
    }else {
        for(int i=0;i<128;++i)
            if(loc->next[i])
                dfs(loc->next[i],i,k,x+1);
    }
    return;
}
*/
