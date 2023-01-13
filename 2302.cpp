#include <bits/stdc++.h>
using namespace std;

int n, m, a[45], fibo[45], ans = 1;
int main() {
   fibo[0] = 1; fibo[1] = 1; fibo[2] = 2;
   for (int i = 3; i <= 40; i++) fibo[i] = fibo[i-1]+fibo[i-2];

   scanf("%d %d", &n, &m);
   int sp = 1;
   for (int i = 1; i <= m; i++) {
      scanf("%d", &a[i]);
      ans *= fibo[a[i]-sp];
      sp = a[i]+1;
   }
   ans *= fibo[n-sp+1];
   printf("%d", ans);
}
