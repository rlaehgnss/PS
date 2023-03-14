#include <bits/stdc++.h>
using namespace std;

char x[1010], y[1010];
int dp[1010] = {0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(NULL);

    cin>>x>>y;
    int lenx = strlen(x), leny = strlen(y);
    for (int i = 0; i < lenx; i++) {
        for (int j = leny-1; j >= 0; j--) {
            if(x[i] == y[j]) {
                dp[j] = max(dp[j-1]+1, dp[j]);
            }
        }
        for (int j = 1; j < leny; j++) dp[j] = max(dp[j], dp[j-1]);
    }
    int ans = 0;
    cout<<dp[leny-1];
}
