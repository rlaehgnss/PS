#include <bits/stdc++.h>
using namespace std;

int main() {
   cin.tie(0);
   ios::sync_with_stdio(NULL);
   int n, h[111], minv = 1111;
   long long v = 1e9+7, ans = 0;
   cin>>n;
   for (int i = 1; i <= n; i++) {
      cin>>h[i];
      minv = min(h[i], minv);
   }
   do {
      long long dp[1010] = {0}, hap[1010] = {0};
      for (int i = 0; i <= h[1]; i++) hap[i] = i+1;
      for (int i = h[1]+1; i <= 1000; i++) hap[i] = h[1]+1;

      for (int i = 2; i <= n; i++) {
         for (int j = 0; j <= h[i]; j++) {
            dp[j] = hap[h[i]-j]%v;
         }
         for (int j = 0; j <= 1000; j++) {
            hap[j] = dp[j];
            if(j>=1)hap[j] += hap[j-1];
            hap[j]%=v;
         }
         fill(dp, dp+1000, 0);
      }
      ans += hap[0];
      for (int i = 1; i <= n; i++) h[i]--;
   } while(minv--&&n%2);
   cout<<ans%v;
}
