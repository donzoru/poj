#pragma optimise ("O2")
#include<cstdio>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
const int M = 30002;
typedef pair<string,int> te;
set<string> ans[M];
set<string>::iterator it,ij;
map<string,int> m;
map<string,int> cnt;
string s,t;
int n;
bool cmp(const te& a, const te& b) {
    if(a.second==b.second) {
        it=ans[m[a.first]].begin();
        ij=ans[m[b.first]].begin();
        return (*it)<(*ij);
    }
    return a.second>b.second;
}
inline void ins()
{
    t=s;
    sort(t.begin(),t.end());
    if(m[t]==0) m[t]=n++;
    ans[m[t]].insert(s);
    cnt[t]++;
}
int main()
{
    n=0;
    m.clear();
    for(int i=0;i<M;++i) ans[i].clear();
    cnt.clear();
    while(cin>>s) ins();
    vector<te> fuck(cnt.begin(),cnt.end());
    sort(fuck.begin(),fuck.end(),cmp);
    for(int i=0;i<fuck.size() && i<5;++i){
        printf("Group of size %d: ",fuck[i].second);
        int tem = m[fuck[i].first];
        for(it=ans[tem].begin();it!=ans[tem].end();++it)
            cout<<*it<<' ';
        puts(".");
    }
    return 0;
}
