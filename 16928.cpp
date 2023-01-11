#include <bits/stdc++.h>
using namespace std;

int n, m, a[111], chkvisit[111] = {0};

void bfs() {
   int ans = 0;
   queue<int> q;
   q.push(1); chkvisit[1] = 1;
   while(!q.empty()) {
      int s = q.size(), chk = 0; ans++;
      while(s--) {
         int t = q.front(); q.pop();
         for(int i = 1; i <= 6; i++) {
            if(t+i > 100 || chkvisit[a[t+i]] == 1) continue;
            else if(a[t+i] == 100) {chk = 1; break;}
            else {chkvisit[a[t+i]] = 1; q.push(a[t+i]);}
         }
      }
      if(chk == 1) {printf("%d", ans); exit(0);}
   }
}

int main() {
   scanf("%d %d", &n, &m);
   for (int i = 1; i <= 100; i++) a[i] = i;
   for (int i = 1; i <= n+m; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      a[x] = y;
   }
   bfs();

}
