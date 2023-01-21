#include <bits/stdc++.h>
using namespace std;

int a[111][111][111] = {{{0}}};

int f(int x, int y, int z) {
   if(a[x+50][y+50][z+50] != -1e9) return a[x+50][y+50][z+50];

   if(x <= 0 || y <= 0 || z <= 0) return a[x+50][y+50][z+50] = 1;
   if(x > 20 || y > 20 || z > 20) return a[x+50][y+50][z+50] = f(20, 20, 20);
   if(x < y && y < z) return a[x+50][y+50][z+50] = f(x, y, z-1)+f(x, y-1, z-1)-f(x, y-1, z);
   return a[x+50][y+50][z+50] = f(x-1, y, z)+f(x-1, y-1, z)+f(x-1, y, z-1)-f(x-1,y-1,z-1);
}

int main() {
   for (int i = 0; i <= 100; i++) {
      for (int j = 0; j <= 100; j++) {
         for (int k = 0; k <= 100; k++) a[i][j][k] = -1e9;
      }
   }
   while(1) {
      int x, y, z;
      scanf("%d %d %d", &x, &y, &z);
      if(x==-1&&y==-1&&z==-1) break;
      printf("w(%d, %d, %d) = %d\n", x, y, z, f(x, y, z));
      
   }
}
