#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v[101010];
int n, chk[101010] = {0};

void dfs(int start, int cur, int dis) {
   chk[cur] = dis;
   chk[start] = -1;
   for (int i = 0; i < v[cur].size(); i++) {
      if(chk[v[cur][i].first] == 0) {
         dfs(start, v[cur][i].first, dis+v[cur][i].second);
      }
   }
}

int main() {
   scanf("%d", &n);
   for (int i = 1; i <= n; i++) {
      int x, a, b;
      scanf("%d", &x);
      while(1) {
         scanf("%d", &a);
         if(a == -1) break;
         scanf("%d", &b);
         v[x].push_back({a, b});
      }
   }
   dfs(1, 1, 0);
   int farest, val = 0;
   for (int i = 1; i <= n; i++) {
      if(val < chk[i]) {farest = i; val = chk[i];}
      chk[i] = 0;
   }
   dfs(farest, farest, 0);
   val = 0;
   for (int i = 1; i <= n; i++) {
      if(val < chk[i]) {farest = i; val = chk[i];}
   }
   printf("%d", val);
}

