#include <bits/stdc++.h>
using namespace std;

int n, a[111][11] = {{0}};

int main() {
   scanf("%d", &n);
   for (int i = 1; i <= 9; i++) a[1][i] = 1;
   for (int i = 1; i < n; i++) {
      for (int j = 0; j <= 9; j++) {
         if(a[i][j]) {
            if(j != 9) a[i+1][j+1] += a[i][j];
            if(j != 0) a[i+1][j-1] += a[i][j];
         }
         a[i+1][j+1] %= 1000000000;
         a[i+1][j-1] %= 1000000000;
      }
   }
   long long ans = 0;
   for (int i = 0; i <= 9; i++) {
      ans += a[n][i];
      ans %= 1000000000;
   }
   printf("%lld", ans);
}
