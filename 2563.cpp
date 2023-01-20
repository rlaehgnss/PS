#include <bits/stdc++.h>
using namespace std;

int a[111][111] = {{0}}, n;

int main() {
   scanf("%d", &n);
   while(n--) {
      int x, y;
      scanf("%d %d", &x, &y);
      for (int i = x; i < x+10; i++) {
         for (int j = y; j < y+10; j++) {
            a[i][j] = 1;
         }
      }
   }
   int ans = 0;
   for (int i = 0; i <= 100; i++) {
      for (int j = 0; j <= 100; j++) {
         if(a[i][j]) ans++;
      }
   }
   printf("%d", ans);
}
