#include <bits/stdc++.h>
using namespace std;

int n, h[2020], Q, ans = 0;
set<int> s[2020];

bool ope(int v, int x, int y) {
   double val1 = double(h[x]-h[v])/(x-v);
   double val2 = double(h[y]-h[v])/(y-v);
   return val1 <= val2;
}

int main() {
   scanf("%d", &n);
   for (int i = 1; i<= n; i++) scanf("%d", &h[i]);
   for (int i = 1; i < n; i++) {
      for (int j = i+1; j <= n; j++) {
         if(s[i].empty()) s[i].insert(j);
         else if(ope(i, *s[i].rbegin(), j)) s[i].insert(j);
      }
   }
   int ans = 0;
   for (int i = 1; i < n; i++) ans += s[i].size();
   scanf("%d", &Q);
   while(Q--) {
      int x, y;
      scanf("%d %d", &x, &y);
      h[x]+=y;

      for (int i = 1; i < x; i++) {
         auto t = s[i].lower_bound(x);
         int chk = 0;
         if(*t == x) {chk = 1;t++;}
         else {
            --t;
            if(ope(i, *t, x)) {
               chk = 1;
               s[i].insert(x);
               ans++;
               t++; t++;
            }
         }
         if(chk) {
            while(t != s[i].end() && !ope(i, x, *t)) {
               t = s[i].erase(t);
               ans--;
            }
         }
      }

      ans -= s[x].size();
      s[x].clear();
      for (int i = x+1; i <= n; i++) {
         if(s[x].empty()) s[x].insert(i);
         else if(ope(x, *s[x].rbegin(), i)) s[x].insert(i);
      }
      ans += s[x].size();
      printf("%d\n", ans);
   }

}

