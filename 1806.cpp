#include <bits/stdc++.h>
using namespace std;

int n, s, a[101010], ans=1e9;

int main() {
   cin.tie(0);
   ios::sync_with_stdio(NULL);
   cin>>n>>s;
   for (int i = 1; i <= n; i++) cin>>a[i];

   int l = 1, r = 1, hap = a[1];
   while(l <= n && r <= n && l<=r) {
      if(hap < s) {hap += a[++r];}
      else if(hap >= s) {ans = min(ans, r-l+1); hap-=a[l++];}
   }
   if(ans==1e9) cout<<"0";
   else cout<<ans;
}
