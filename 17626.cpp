#include <bits/stdc++.h>
using namespace std;

int n, a[255] = {0}, dp[50505] = {0};

int main() {
   scanf("%d", &n);
   for (int i = 1; i <= 233; i++) a[i] = i*i;
   int cur = 1;
   for (int i = 1; i <= n; i++) {
      if(a[cur] == i) {
         dp[i] = 1; cur++;
      }
      else {
         dp[i] = 1e9;
         for (int j = 1; j < cur; j++) dp[i] = min(dp[i-j*j]+1, dp[i]);
      }
   }
   printf("%d", dp[n]);
}
