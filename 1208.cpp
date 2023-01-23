#include <bits/stdc++.h>
using namespace std;

int n, s, mp[10101010] = {0}, a[44];
long long ans = 0                                                            ;

void f(int cur, int hap) {
   if(cur > n/2) {mp[hap+4000000] += 1; return;}
   f(cur+1, hap+a[cur]);
   f(cur+1, hap);
}

void f2(int cur, int hap) {
   if(cur > n) {
      if(mp[s-hap+4000000]>0) ans+=mp[s-hap+4000000];
      return;
   }
   f2(cur+1, hap+a[cur]);
   f2(cur+1, hap);
}
int main() {
   cin.tie(0);
   ios::sync_with_stdio(NULL);

   cin >> n >> s;
   for (int i = 1; i <= n; i++) cin>>a[i];
   f(1, 0);
   f2(n/2+1, 0);
   if(s==0) cout<<ans-1;
   else cout<<ans;
}
