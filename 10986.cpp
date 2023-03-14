#include <bits/stdc++.h>
using namespace std;

int n, m, v[1010] = {0};
long long a[1010101];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(NULL);
    cin>>n>>m;
    long long sum = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
        sum += a[i];
        if(sum%m == 0) ans++;
        v[sum%m]++;
    }
    for (int i = 0; i < m; i++) {
        ans += (long long)v[i]*(v[i]-1)/2;
    }
    cout<<ans;
}
