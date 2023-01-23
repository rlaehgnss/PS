#include <bits/stdc++.h>
using namespace std;

int a[4040404] = {0}, n, ans = 0;
vector<int>prime;

int main() {
   cin.tie(0);
   ios::sync_with_stdio(NULL);
   prime.push_back(0);
   for (int i = 2; i <= 4000000; i++) {
      if(!a[i]) {
         for (int j = i*2; j <= 4000000; j+=i) a[j]=1;
         prime.push_back(i);
      }
   }
   prime.push_back(0);
   cin>>n;
   int l = 1, r = 1, s = prime.size()-2, hap = prime[1];
   while(l <= r && l <= s && r <= s) {
      if(hap < n) {hap+=prime[++r];}
      else if(hap == n) {ans++; hap -= prime[l++];}
      else {hap -= prime[l++];}
   }
   cout<<ans;
}
