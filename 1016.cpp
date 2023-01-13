#include <bits/stdc++.h>
using namespace std;

long long x, y, i, j, k;
int a[1010101] = {0}, ans = 0;

int main() {
   scanf("%lld %lld", &x, &y);
   for (j = 2; j*j <= y; j++) {
      long long sp;
      if(x%(j*j) == 0) sp = x;
      else sp = (x/(j*j) + 1)*(j*j);

      for (k = 0; sp+(j*j*k) <= y; k++) {
         a[sp+j*j*k-x] = 1;
      }
   }
   for (i = x; i <= y; i++) {
      if(a[i-x] == 0) ans++;
   }
   printf("%d", ans);
}
