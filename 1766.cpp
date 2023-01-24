#include <bits/stdc++.h>
using namespace std;

int n, m, indeg[32323] = {0};
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> v[32323], ans;
int main() {
   cin.tie(0);
   ios::sync_with_stdio(NULL);
   cin>>n>>m;
   for (int i = 1; i <= m; i++) {
      int x, y;
      cin>>x>>y;
      v[x].push_back(y);
      indeg[y]++;
   }
   for (int i = 1; i <= n; i++) {
      if(indeg[i] == 0) pq.push(i);
   }
   while(!pq.empty()) {
      int val = pq.top(); pq.pop();
      ans.push_back(val);
      for (int i = 0; i < v[val].size(); i++) {
         if(--indeg[v[val][i]] == 0) pq.push(v[val][i]);
      }
   }
   for (int i = 0; i < ans.size(); i++) cout<<ans[i]<<" ";
}
