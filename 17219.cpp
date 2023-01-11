#include <bits/stdc++.h>
using namespace std;

int n, m;
map<string, string> p;
struct data {
   char site[25], password[25];
   bool operator<(const data&r) const{
      if(strcmp(site, r.site) > 0) return site < r.site;
      else return site > r.site;
   }
}a[101010];

int main() {
   cin.tie(NULL);
   ios::sync_with_stdio(false);
   cin>>n>>m;
   for (int i = 1; i <= n; i++) {
      string x, y;
      cin>>x>>y;
      p.insert({x,y});
   }
   for (int i = 1; i <= m; i++) {
      string x;
      cin>>x;
      cout << p[x] << "\n";
   }
}
