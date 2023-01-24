#include <bits/stdc++.h>
using namespace std;

int t, n, a[505], m;

int main() {
   cin.tie(0);
   ios::sync_with_stdio(NULL);
   cin>>t;
   while(t--) {
      int chk[505] = {0}, chk2[505][505] = {{0}}, tmp[505] = {0}, ans = 0, out[505];
      cin>>n;
      for (int i = 1; i <= n; i++) {
         cin>>a[i];
         chk[a[i]] = n-i;
      }
      for (int i = n; i > 1; i--) {
         for (int j = i-1; j >= 1; j--) chk2[a[j]][a[i]] = 1;
      }
      cin>>m;
      for (int i = 1; i <= m; i++) {
         int x, y;
         cin>>x>>y;
         if(chk2[x][y] == 1) {
            chk[x]--;
            chk[y]++;
         }
         else {
            chk[y]--;
            chk[x]++;
         }
      }
      for (int i = 1; i <= n; i++) {
         tmp[chk[i]]++;
         out[chk[i]] = i;
      }
      for (int i = 0; i < n; i++) {
         if(tmp[i]==0 || tmp[i] > 1) ans=1;
      }
      if(ans) cout<<"IMPOSSIBLE\n";
      else {
         for (int i = n-1; i >= 0; i--) cout<<out[i]<<" ";
         cout<<"\n";
      }
   }
}
