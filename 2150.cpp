#include <bits/stdc++.h>
using namespace std;

int vv, e, chk[101010] = {0}, cnt = 0;
vector<int> v[101010], r_v[101010], ans[101010], s;
struct data{
   int n, v;
   bool operator<(const data&r) const{
      return v < r.v;
   }
}a[101010];

void dfs(int cp) {
   chk[cp] = 1;

   if(!v[cp].empty()) sort(v[cp].begin(), v[cp].end());
   for (int i = 0; i < v[cp].size(); i++) {
      if(chk[v[cp][i]] == 1) continue;
      dfs(v[cp][i]);
   }
   s.push_back(cp);
}

void reverse_dfs(int cp) {
   chk[cp] = 1;
   ans[cnt].push_back(cp);
   if(!r_v[cp].empty()) sort(r_v[cp].begin(), r_v[cp].end());
   for (int i = 0; i < r_v[cp].size(); i++) {
      if(chk[r_v[cp][i]] == 1) continue;
      reverse_dfs(r_v[cp][i]);
   }
}

int main() {
   scanf("%d %d", &vv, &e);
   for (int i = 1; i <= e; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      v[x].push_back(y);
      r_v[y].push_back(x);
   }

   for (int i = 1; i <= vv; i++) {
      if(chk[i] == 0) dfs(i);
   }

   memset(chk, 0, sizeof(chk));

   while(!s.empty()) {
      int cur = s.back(); s.pop_back();
      if(chk[cur]) continue;
      reverse_dfs(cur);
      cnt++;
   }

   printf("%d\n", cnt);
   for (int i = 0; i < cnt; i++) {
      sort(ans[i].begin(), ans[i].end());
      a[i].n = i; a[i].v = ans[i][0];
   }
   sort(a,a+cnt);
   for (int i = 0; i < cnt; i++) {
      for (int j = 0; j < ans[a[i].n].size(); j++) printf("%d ", ans[a[i].n][j]);
      printf("-1\n");
   }

}
