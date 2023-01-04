#include <bits/stdc++.h>
using namespace std;

int n, m, in[101][101], a[101][101], chk[101][101] = {{0}}, xx[4] = {1, -1, 0, 0}, yy[4] = {0, 0, 1, -1}, chkbfs[10101] = {0}, ans = 1e9;
vector<int> con[10101];
set<pair<int, int>> s;

void match(int x, int y, int val) {
   chk[x][y] = 1;
   a[x][y] = val;
   for (int i = 0; i < 4; i++) {
      int nx = x+xx[i], ny = y+yy[i];
      if(nx >= 1 && ny >= 1 && nx <= n && ny <= m && chk[nx][ny]==0 && in[x][y] == in[nx][ny]) match(nx, ny, val);
   }
}

void bfs(int sp, int num) {
   int chkvisit[num+1] = {0}, val = 0, chknew = 0;
   queue<int> q;
   q.push(sp); chkvisit[sp] = 1;
   while(!q.empty()) {
      int s = q.size();
      for (int i = 0; i < s; i++) {
         int p = q.front(); q.pop();
         for (int j = 0; j < con[p].size(); j++) {
            if(chkvisit[con[p][j]] == 0) {
               chkvisit[con[p][j]] = 1;
               if(val >= ans) chkbfs[con[p][j]] = 1;
               else {q.push(con[p][j]); chknew = 1;}
            }
         }
      }
      if(chknew) {val++; chknew = 0;}
   }
   ans = min(ans, val);
}

int main() {
   scanf("%d %d", &n, &m);
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) scanf("%d", &in[i][j]);
   }
   //같은 색 돌들 하나로 묶기
   int cnt = 1;
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         if(!chk[i][j]) {
            match(i, j, cnt);
            cnt++;
         }
      }
   }
   //연결그래프로 표현
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         for (int k = 0; k < 4; k++) {
            int x = i+xx[k], y = j+yy[k];
            if(x >= 1 && y >= 1 && x <= n && y <= m && a[i][j] != a[x][y] && s.find({a[i][j], a[x][y]}) == s.end()) {
               con[a[i][j]].push_back(a[x][y]);
               con[a[x][y]].push_back(a[i][j]);
               s.insert({a[i][j], a[x][y]});
               s.insert({a[x][y], a[i][j]});
            }
         }
      }
   }
   //연결그래프의 최대 길이 구하기
   for (int i = 1; i < cnt; i++) {
      if(chkbfs[i] == 0) {
         bfs(i, cnt-1);
      }
   }
   printf("%d", ans);
   return 0;
}
