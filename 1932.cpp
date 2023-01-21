#include <bits/stdc++.h>
using namespace std;

int a[505][505] = {{0}}, ans[505][505] = {{0}}, n, maxx = -1;

int main() {
   scanf("%d", &n);
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) scanf("%d", &a[i][j]);
   }
   ans[1][1] = a[1][1];
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
         ans[i+1][j] = max(ans[i+1][j], ans[i][j]+a[i+1][j]);
         ans[i+1][j+1] = max(ans[i+1][j+1], ans[i][j]+a[i+1][j+1]);
         maxx = max({maxx, ans[i+1][j], ans[i+1][j+1]});
      }
   }
   printf("%d", maxx);
}
