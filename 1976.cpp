#include <bits/stdc++.h>
using namespace std;

int n, m, a[222], p[1010];

int f(int val) {
   if(a[val] == val) return val;
   return a[val] = f(a[val]);
}

void mg(int x, int y) {
   x = f(x);
   y = f(y);
   if(x != y) a[x] = y;
}

int isUnion(int x, int y) {
   x = f(x);
   y = f(y);
   if(x ==y) return 1;
   else return 0;
}

int main() {
   scanf("%d %d", &n, &m);
   for (int i = 1; i <= n; i++) a[i] = i;
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
         int x;
         scanf("%d", &x);
         if(x == 1) mg(i, j);
      }
   }
   for (int i = 1; i <= m; i++) scanf("%d", &p[i]);
   int chk = 0;
   for (int i = 2; i <= m; i++) {
      if(!isUnion(p[1], p[i])) chk = 1;
   }
   if(chk) printf("NO");
   else printf("YES");
}
