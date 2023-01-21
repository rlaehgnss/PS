#include <bits/stdc++.h>
using namespace std;

int n, a[1010], dp[1010] = {0}, maxx = 0;

int main() {
   scanf("%d", &n);
   a[0] = -1;
   for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      for (int j = i-1; j >= 0; j--) {
         if(a[j] < a[i]) dp[i] = max(dp[i], dp[j]+1);
      }
      maxx = max(maxx, dp[i]);
   }
   printf("%d", maxx);

}
