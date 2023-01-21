#include <bits/stdc++.h>
using namespace std;

int n, a[10101], dp[10101][4] = {{0}};

int main() {
   scanf("%d", &n);
   for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      dp[i][0] = dp[i-1][3];
      dp[i][1] = dp[i-1][0]+a[i];
      dp[i][2] = dp[i-1][1]+a[i];
      dp[i][3] = max({dp[i][0], dp[i][1], dp[i][2]});
   }
   printf("%d", dp[n][3]);
}
