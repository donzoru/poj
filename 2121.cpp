#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
using namespace std;
map<string,int> m;
void init()
{
    m.clear();
    m["zero"]=0;
    m["one"]=1;
    m["two"]=2;
    m["three"]=3;
    m["four"]=4;
    m["five"]=5;
    m["six"]=6;
    m["seven"]=7;
    m["eight"]=8;
    m["nine"]=9;
    m["ten"]=10;
    m["eleven"]=11;
    m["twelve"]=12;
    m["thirteen"]=13;
    m["fourteen"]=14;
    m["fifteen"]=15;
    m["sixteen"]=16;
    m["seventeen"]=17;
    m["eighteen"]=18;
    m["nineteen"]=19;
    m["twenty"]=20;
    m["thirty"]=30;
    m["forty"]=40;
    m["fifty"]=50;
    m["sixty"]=60;
    m["seventy"]=70;
    m["eighty"]=80;
    m["ninety"]=90;
    m["hundred"]=100;
    m["thousand"]=1000;
    m["million"]=1000000;
}
int main()
{
    init();
    int ans,sum,t;
    char s[100003],*p;
    while(gets(s) && s[0]!=0){
        ans=sum=0;
        p=strtok(s," ");
        if(!strcmp(p,"negative")) putchar('-');
        else sum=m[p];
        p=strtok(NULL," ");
        while(p){
            t=m[p];
            if(t<100) sum+=t;
            else if(t==100) sum*=100;
            else{
                ans+=sum*t;
                sum=0;
            }
            p=strtok(NULL," ");
        }
        printf("%d\n",ans+sum);
    }
    return 0;
}
