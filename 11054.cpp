#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a[1010], g[1010] = {0}, d[1010] = {0}, ans = 0;
    cin.tie(0);
    ios::sync_with_stdio(NULL);
    cin>>n;
    for (int i = 1; i <= n; i++) cin>>a[i];
    g[1]=1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if(a[i]>a[j]) g[i]=max(g[i], g[j]+1);
        }
        if(g[i]==0) g[i]=1;
    }
    d[n] = 1;
    for (int i = n-1; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            if(a[i]>a[j]) d[i]=max(d[i], d[j]+1);
        }
        if(d[i]==0) d[i]=1;
    }
    for (int i = 1; i <= n; i++) {
        ans = max(ans, d[i]+g[i]-1);
    }
    cout<<ans;
}
