#include <bits/stdc++.h>
using namespace std;

int t, k, a[505], dp[505][505] = {0};

int f(int l, int r) {
    if(dp[l][r] != 0) return dp[l][r];
    if(l==r) return 0;
    if(r-l==1) return dp[l][r]=a[r]+a[l];
    dp[l][r] = 1e9;
    int s = 0;
    for (int i = l; i < r; i++) {
        dp[l][r] = min(dp[l][r], f(l, i)+f(i+1, r));
        s+=a[i];
    }
    return dp[l][r]=dp[l][r]+s+a[r];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(NULL);

    cin>>t;
    while(t--) {
        cin>>k;
        for (int i = 1; i <= k; i++) cin>>a[i];
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= k; j++) dp[i][j]=0;
        }
        cout<<f(1, k)<<"\n";
    }
}
