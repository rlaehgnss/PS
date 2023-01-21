#include <bits/stdc++.h>
using namespace std;

int n, a[101010], ans[101010], maxx = -1e9;

int main() {
   scanf("%d", &n);
   for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      ans[i]=max(ans[i-1]+a[i], a[i]);
      maxx = max(maxx, ans[i]);
   }
   printf("%d", maxx);
}
