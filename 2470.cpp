#include <bits/stdc++.h>
using namespace std;

int n, a[101010], ansval = 2e9+1, ans1, ans2;

int main() {
   cin.tie(0);
   ios::sync_with_stdio(NULL);

   cin >>n;
   for (int i =1; i <= n; i++) cin>>a[i];
   sort(a+1, a+n+1);
   int l = 1, r = n;
   while(l<r) {
      if(ansval > abs(a[l]+a[r])) {
         ansval = abs(a[l]+a[r]);
         ans1 = a[l]; ans2 = a[r];
      }
      if(a[l]+a[r] > 0) r--;
      else l++;
   }
   cout<<ans1<<" "<<ans2;
}
