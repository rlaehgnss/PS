#include <bits/stdc++.h>
using namespace std;

int main() {
   int n, k;
   scanf("%d %d", &n, &k);
   if(n*2 < k) {
      printf("2");
      return 0;
   }
   if(n*2 %k != 0) printf("%d", n*2/k+1);
   else printf("%d", n*2/k);
   return 0;
}
