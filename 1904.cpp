#include <bits/stdc++.h>
using namespace std;

long long c[1010101];
int n;

int main() {
   scanf("%d", &n);
   c[1] = 1; c[2] = 2;
   for (int i = 3; i <= n; i++) {
      c[i] = (c[i-1]+c[i-2])%15746;
   }
   printf("%lld", c[n]);
}
