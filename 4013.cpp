#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 0, indegvisit[505050] = {0}, val[505050] = {0}, s, p, r[505050] = {0}, chk[505050] = {0}, scc[505050] = {0};
vector<int> v[505050], r_v[505050], st, indeg[505050], c[505050], visits;
set<int> tmp[505050];
long long scchap[505050] = {0}, dp[505050] = {0};

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

void sccindeg(int cur) {
   visits = vector<int>(cnt+1, 0);
   visits[cur] = 1;
   for (int i = 0; i < c[cur].size(); i++) {
      for (int j = 0; j < v[c[cur][i]].size(); j++) {
         if(!visits[scc[v[c[cur][i]][j]]]) {
            indeg[cur].push_back(scc[v[c[cur][i]][j]]);
            visits[scc[v[c[cur][i]][j]]] = 1;
         }
      }
   }
}

void sdfs(int cur) {
   indegvisit[cur] = 1;
   for (int i = 0; i < indeg[cur].size(); i++) {
      if(indegvisit[indeg[cur][i]]) {
         if(dp[cur]+scchap[indeg[cur][i]] > dp[indeg[cur][i]]) {
            dp[indeg[cur][i]] = dp[cur]+scchap[indeg[cur][i]];
            sdfs(indeg[cur][i]);
         }
      }
      else {
         dp[indeg[cur][i]] = dp[cur]+scchap[indeg[cur][i]];
         sdfs(indeg[cur][i]);
      }
   }
}

int main() {
   scanf("%d %d", &n, &m);
   for (int i = 1; i <= m; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      v[x].push_back(y);
      r_v[y].push_back(x);
   }
   for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
   scanf("%d %d", &s, &p);
   for (int i = 1; i <= p; i++){
      scanf("%d", &r[i]);
   }

   for (int i = 1; i <= n; i++) {
      if(!chk[i]) dfs(i);
   }
   for (int i = st.size()-1; i >= 0; i--) {
      if(!scc[st[i]]) {cnt++; rdfs(st[i]);}
   }
   for (int i = 1; i <= n; i++) {
      scchap[scc[i]] += val[i];
      c[scc[i]].push_back(i);
   }
   for (int i = 1; i <= n; i++) {
      for (int j = 0; j < v[i].size(); j++) {
         if(scc[i] != scc[v[i][j]]) {
            tmp[scc[i]].insert(scc[v[i][j]]);
         }
      }
   }

   for (int i = 1; i <= cnt; i++) {
      for (auto e : tmp[i]) {
         indeg[i].push_back(e);
      }
   }
   dp[scc[s]] = scchap[scc[s]];
   sdfs(scc[s]);
   long long ans = 0;
   for (int i = 1; i <= p; i++) {
      ans = max(ans, dp[scc[r[i]]]);
   }
   printf("%lld", ans);
}
