#include <bits/stdc++.h>
using namespace std;

int n, c, a[33];
long long ans = 0;
vector<long long> v;

void f(int cur, long long hap) {
   if(hap > c) return;
   if(cur > n/2) {
      v.push_back(hap);
      return;
   }

   f(cur+1, hap+a[cur]);
   f(cur+1, hap);
}

void f2(int cur, long long hap) {
   if(hap > c) return;
   if(cur > n) {
      vector<long long>::iterator iter;
      iter = upper_bound(v.begin(), v.end(), c-hap);
      ans += iter-v.begin();
      return;
   }

   f2(cur+1, hap+a[cur]);
   f2(cur+1, hap);
}

int main() {
   cin.tie(0);
   ios::sync_with_stdio(NULL);
   cin>>n>>c;
   for (int i = 1; i <= n; i++) cin>>a[i];
   f(1, 0);
   sort(v.begin(), v.end());
   f2(n/2+1, 0);
   cout<<ans;
}
