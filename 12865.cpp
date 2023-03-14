#include <bits/stdc++.h>
using namespace std;

int n, k, dp[101010] = {0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(NULL);

    cin>>n>>k;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin>>x>>y;
        for (int j = k-x; j >=1; j--) {
            if(dp[j] != 0) {
                dp[j+x] = max(dp[j+x], dp[j]+y);
            }
        }
        dp[x] = max(dp[x], y);
    }
    int ans=0;
    for (int i = 1; i <= k; i++) {
        ans = max(dp[i], ans);
    }
    cout<<ans;
}
