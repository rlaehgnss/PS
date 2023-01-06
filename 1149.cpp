#include <bits/stdc++.h>
using namespace std;

int n, dp[1010][3] = {{0}};

int main() {
   scanf("%d", &n);
   for (int i = 1; i <= n; i++) {
      int r, g, b;
      scanf("%d %d %d", &r, &g, &b);
      dp[i][0] = min(dp[i-1][1], dp[i-1][2])+r;
      dp[i][1] = min(dp[i-1][0], dp[i-1][2])+g;
      dp[i][2] = min(dp[i-1][0], dp[i-1][1])+b;
   }
   printf("%d", min({dp[n][0], dp[n][1], dp[n][2]}));
}
