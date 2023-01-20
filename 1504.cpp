#include <bits/stdc++.h>
using namespace std;

int n, e, v1, v2;
long long c[3][888];
vector<pair<int, int>> v[888];

void dijkstra(int q, int start) {
   c[q][start] = 0;
   priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>pq;
   pq.push({0, start});
   while(!pq.empty()) {
      long long val = pq.top().first;
      int cur = pq.top().second;
      pq.pop();

      if(c[q][cur] < val) continue;
      for (int i = 0; i < v[cur].size(); i++) {
         if(c[q][v[cur][i].first] > val+v[cur][i].second) {
            c[q][v[cur][i].first] = val+v[cur][i].second;
            pq.push({c[q][v[cur][i].first], v[cur][i].first});
         }
      }
   }
}

int main() {
   scanf("%d %d", &n, &e);
   for (int i = 1; i <= e; i++) {
      int x, y, z;
      scanf("%d %d %d", &x, &y, &z);
      v[x].push_back({y, z});
      v[y].push_back({x, z});
   }
   for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= 2; j++) c[j][i] = 2e12;
   }
   scanf("%d %d", &v1, &v2);
   dijkstra(0, 1);
   dijkstra(1, v1);
   dijkstra(2, v2);
   long long ans = min(c[0][v1]+c[1][v2]+c[2][n], c[0][v2]+c[2][v1]+c[1][n]);
   if(ans >= 1e9) printf("-1");
   else printf("%lld", ans);
}
