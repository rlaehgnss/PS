#include <bits/stdc++.h>
using namespace std;

int n, a, b, dp[2020][4040];
struct data {
   int p, c, x;
   bool operator <(const data&r) const{
      return x < r.x;
   }
}f[2020];

int main() {
   scanf("%d %d %d", &n, &a, &b);
   for (int i = 1; i <= n; i++) {
      scanf("%d %d %d", &f[i].p, &f[i].c, &f[i].x);
   }
   sort(f+1, f+n+1);
   memset(dp, -1, sizeof(dp));

   dp[1][a+b] = 0;
   for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= a+b; j++) {
         if(dp[i][j] == -1) continue;
         dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
         if(j-f[i].c*f[i].x >= a) {
            dp[i+1][j-f[i].c*f[i].x] = max(dp[i+1][j-f[i].c*f[i].x], dp[i][j]+f[i].p);
         }
         else if(j > a) {
            int part = (j-a)/f[i].x;
            dp[i+1][a-f[i].c+part] = max(dp[i+1][a-f[i].c+part], dp[i][j]+f[i].p);
         }
         else if(j-f[i].c >= 0 && j <= a) {
            dp[i+1][j-f[i].c] = max(dp[i+1][j-f[i].c], dp[i][j]+f[i].p);
         }
      }
   }

   int ans = 0;
   for (int i = 0; i <= a+b; i++) ans = max(ans, dp[n+1][i]);
   printf("%d", ans);
}
