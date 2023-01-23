#include <bits/stdc++.h>
using namespace std;

int n, a[1010101], x, ans = 0;

int main() {
   scanf("%d", &n);
   for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
   }
   scanf("%d", &x);
   sort(a+1, a+n+1);
   int l = 1, r = n;
   while(l < r) {
      if(a[l]+a[r] > x) r--;
      else if(a[l]+a[r] == x) {ans++; l++; r--;}
      else l++;
   }
   printf("%d", ans);
}
