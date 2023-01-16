#include <bits/stdc++.h>
using namespace std;

int t, n, m, chk[101010] = {0}, scc[101010] = {0}, cnt = 1, indeg[101010] = {0};
vector<int> v[101010], r_v[101010], st;

void dfs(int cur) {
   chk[cur] = 1;
   sort(v[cur].begin(), v[cur].end());
   for (int i = 0; i < v[cur].size(); i++) {
      if(!chk[v[cur][i]]) dfs(v[cur][i]);
   }
   st.push_back(cur);
}

void rdfs(int cur) {
   scc[cur] = cnt;
   sort(r_v[cur].begin(), r_v[cur].end());
   for (int i = 0; i < r_v[cur].size(); i++) {
      if(!scc[r_v[cur][i]]) rdfs(r_v[cur][i]);
   }
}

int main() {
   scanf("%d", &t);
   while(t--) {
      scanf("%d %d", &n, &m);
      for (int i = 1; i <= m; i++) {
         int x, y;
         scanf("%d %d", &x, &y);
         v[x].push_back(y);
         r_v[y].push_back(x);
      }

      for (int i = 1; i <= n; i++) {
         if(!chk[i]) dfs(i);
      }

      for (int i= st.size()-1; i >= 0; i--) {
         if(!scc[st[i]]) {rdfs(st[i]); cnt++;}
      }

      for (int i = 1; i <= n; i++) {
         for (int j = 0; j < v[i].size(); j++) {
            if(scc[i] != scc[v[i][j]]) indeg[scc[v[i][j]]]++;
         }
      }

      int ans = 0;
      for (int i = 1; i < cnt; i++) {
         if(indeg[i] == 0) ans++;
      }
      printf("%d\n", ans);

      for (int i = 1; i <= n; i++) {v[i].clear(); r_v[i].clear();}
      memset(chk, 0, sizeof(chk));
      memset(scc, 0, sizeof(scc));
      memset(indeg, 0, sizeof(indeg));
      st.clear(); cnt = 1;
   }
}
