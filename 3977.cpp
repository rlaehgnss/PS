#include <bits/stdc++.h>
using namespace std;

int t, vv, e, chk[101010] = {0}, cnt = 0;
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
   chk[cp] = cnt+1;
   ans[cnt].push_back(cp);
   if(!r_v[cp].empty()) sort(r_v[cp].begin(), r_v[cp].end());
   for (int i = 0; i < r_v[cp].size(); i++) {
      if(chk[r_v[cp][i]] != 0) continue;
      reverse_dfs(r_v[cp][i]);
   }
}

int main() {
   scanf("%d", &t);
   while(t--) {
      scanf("%d %d", &vv, &e);
      int indeg[vv+1] = {0};
      for (int i = 1; i <= e; i++) {
         int x, y;
         scanf("%d %d", &x, &y);
         x+=1; y+=1;
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

      for (int i = 1; i <= vv; i++) {
         for (int j = 0; j < v[i].size(); j++) {
            if(chk[i] != chk[v[i][j]]) indeg[chk[v[i][j]]]++;
         }
      }

      int pos = 0, chk2 = 0;
      for (int i = 1; i <= cnt; i++) {
         if(indeg[i] == 0) {pos = i-1; chk2++;}
      }
      if(chk2 != 1) printf("Confused\n\n");
      else {
         sort(ans[pos].begin(), ans[pos].end());
         for(int i = 0; i < ans[pos].size(); i++) printf("%d\n", ans[pos][i]-1);
         printf("\n");
      }

      memset(chk, 0, sizeof(chk));
      for(int i = 1; i <= vv; i++) {v[i].clear(); r_v[i].clear();}
      for (int i = 0; i < cnt; i++) ans[i].clear();
      s.clear(); cnt = 0;
   }

}
