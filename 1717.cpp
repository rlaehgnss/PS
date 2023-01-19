#include <bits/stdc++.h>
using namespace std;

int n, m, a[1010101];

int f(int val) {
   if(a[val] == val) return val;
   return a[val] = f(a[val]);
}

void mg(int y, int z) {
   y = f(y);
   z = f(z);
   a[y] = z;
}

int isUnion(int y, int z) {
   y = f(y);
   z = f(z);
   if(y == z) return 1;
   else return 0;
}

int main() {
   scanf("%d %d", &n, &m);
   for (int i = 1; i <= n; i++) a[i] = i;
   for (int i = 1; i <= m; i++) {
      int x, y, z;
      scanf("%d %d %d", &x, &y, &z);
      if(x == 0) mg(y, z);
      else {
         int t = isUnion(y, z);
         if(t) printf("YES\n");
         else printf("NO\n");
      }
   }
}
