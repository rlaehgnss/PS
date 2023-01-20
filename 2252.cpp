#include <bits/stdc++.h>
using namespace std;

int n, m, indeg[32323] = {0}, chk[32323] = {0};
vector<int> v[32323], ans;
queue<int>q;

int main() {
   scanf("%d %d", &n, &m);
   for (int i = 1; i <= m; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      v[x].push_back(y);
      indeg[y]++;
   }
   for (int i = 1; i <= n; i++) {
      if(indeg[i] == 0) {
         q.push(i);
         chk[i] = 1;
      }
   }
   while(!q.empty()) {
      int val = q.front();
      q.pop();
      ans.push_back(val);
      for (int i = 0; i < v[val].size(); i++) {
         if(chk[v[val][i]] == 0) {
            if(--indeg[v[val][i]] == 0) {
               chk[v[val][i]] = 1;
               q.push(v[val][i]);
            }
         }
      }
   }
   for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
}
