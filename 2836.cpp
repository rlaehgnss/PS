#include <bits/stdc++.h>
using namespace std;

int n, m;
long long sum = 0;
vector<pair<long long, long long>> a;

int main() {
   cin.tie(0);
   ios::sync_with_stdio(NULL);
   cin>>n>>m;
   for (int i = 1; i<=n; i++) {
      long long x, y;
      cin>>x>>y;
      if(x>y)a.push_back({y, x});
   }
   if(!a.empty()) {
      sort(a.begin(), a.end());
      long long right = a[0].second, left = a[0].first;
      for (int i = 1; i < a.size(); i++) {
         if(right < a[i].first) {
            sum += (right-left)*2;
            right = a[i].second;
            left = a[i].first;
         }
         else right = max(right, a[i].second);
      }
      sum += (right-left)*2;
   }
   cout<<m+sum;
}
