#include <bits/stdc++.h>
using namespace std;

int dp[1010101], n, k;

void dijkstra(int start) {
   dp[start] = 0;
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   pq.push({0, start});
   while(!pq.empty()) {
      int val = pq.top().first;
      int cur = pq.top().second;
      pq.pop();

      if(dp[cur] < val) continue;
      if(dp[cur*2] > dp[cur] && cur <= 100000) {
         dp[cur*2] = dp[cur];
         pq.push({dp[cur], cur*2});
      }
      if(dp[cur+1] > dp[cur]+1 && cur <= 100000) {
         dp[cur+1] = dp[cur]+1;
         pq.push({dp[cur]+1, cur+1});
      }
      if(dp[cur-1] > dp[cur]+1 && cur >= 1) {
         dp[cur-1] = dp[cur]+1;
         pq.push({dp[cur]+1, cur-1});
      }
   }
}

int main() {
   scanf("%d %d", &n, &k);
   for (int i = 0; i <= 200000; i++) dp[i] = 1e9;
   dijkstra(n);
   printf("%d", dp[k]);
}
