#include <bits/stdc++.h>
using namespace std;
int n, a[130][130], bc = 0, wc = 0;

void divi(int xs, int ys, int xe, int ye) {
   int chk = 0;
   for (int i = xs; i <= xe; i++) {
      for (int j = ys; j <= ye; j++) {
         if(a[i][j] != a[xs][ys]) {chk = 1; break;}
      }
   }
   if(chk == 0) {
      if(a[xs][ys] == 0) wc++;
      else bc++;
      return;
   }
   else {
      divi(xs, ys, (xe-xs+1)/2+xs-1, (ye-ys+1)/2+ys-1);
      divi(xs, (ye-ys+1)/2+ys, (xe-xs+1)/2+xs-1, ye);
      divi((xe-xs+1)/2+xs, ys, xe, (ye-ys+1)/2+ys-1);
      divi((xe-xs+1)/2+xs, (ye-ys+1)/2+ys, xe, ye);
   }
}

int main() {
   scanf("%d", &n);
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
   }
   divi(1, 1, n, n);
   printf("%d\n%d", wc, bc);
}
