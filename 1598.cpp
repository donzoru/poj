#include<cstdio>
#include<string>
#include<vector>
#include<set>
#include<cctype>
#include<iostream>
#include<sstream>
using namespace std;
set<string> ss;
set<string>::iterator it;
string s,t;
vector<string> ans;
int n,m;
int cnt;
inline void tol()
{
    for(int i=0;i<s.length();++i)
        if(isalpha(s[i])) s[i]=tolower(s[i]);
        else s[i]=' ';
}
int main()
{
    cnt=1;
    while(scanf("%d%d",&n,&m)!=EOF){
        ss.clear();
        ans.clear();
        while(n--){
            cin>>s;
            tol();
            ss.insert(s);
        }
        getchar();
        for(int i=0;i<m;++i){
            getline(cin,t);
            s=t;
            tol();
            int c=0;
            istringstream is(s);
            for(string a;is>>a;)
                if(ss.count(a))
                    ++c;
            if(n<=c){
                if(n<c) ans.clear();
                n=c;
                ans.push_back(t);
            }
        }
        printf("Excuse Set #%d\n",cnt++);
        for(int i=0;i<ans.size();++i)
            cout<<ans[i]<<endl;
        putchar('\n');
    }
    return 0;
}
/*
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <cctype>
#include <iterator>
#include <algorithm>
using namespace std;

char downcase(char c) { return tolower(c); }
char cleanup(char c) { return isalpha(c) ? tolower(c) : ' '; }

int main()
{
  ios::sync_with_stdio(false);
  for (int K, E, Ti = 1; cin >> K >> E; Ti++) {
    set<string> keywords;
    for (int i = 0; i < K; i++) {
      string s;
      cin >> s;
      transform(s.begin(), s.end(), s.begin(), downcase);
      keywords.insert(s);
    }

    cin.ignore();
    vector<string> ans;
    int m = 0;
    for (int i = 0; i < E; i++) {
      string line;
      getline(cin, line);
      const string orig_line = line;
      transform(line.begin(), line.end(), line.begin(), cleanup);
      istringstream iss(line);
      cout<<line<<endl;
      int c = 0;
      for (string s; iss >> s;) {
        if (keywords.count(s)) {
          ++c;
        }
      }
      if (c > m) {
        m = c;
        ans.clear();
        ans.push_back(orig_line);
      } else if (c == m) {
        ans.push_back(orig_line);
      }
    }
    cout << "Excuse Set #" << Ti << endl;
    copy(ans.begin(), ans.end(), ostream_iterator<string>(cout, "\n"));
    cout << endl;
  }
  return 0;
}
*/
