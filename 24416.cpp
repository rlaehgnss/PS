#include <bits/stdc++.h>
using namespace std;

int n, fibo[44], ans = 0;

int f(int x) {
   if(x == 1 || x == 2) {ans++; return 1;}
   else return (f(x-1)+f(x-2));
}

int main() {
   scanf("%d", &n);
   f(n);
   printf("%d %d", ans, n-2);
}
