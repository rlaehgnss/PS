#include <bits/stdc++.h>
using namespace std;

int n, a[33], dp[404040] = {0}, t;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(NULL);

    cin>>n;
    for (int i = 1; i <= n; i++) cin>>a[i];
    for (int j = 1; j <= n; j++) {
        queue<int>q;
        for (int i = 0; i <= 30000; i++) {
            if(dp[i] == 1) q.push(i);
        }
        while(!q.empty()) {
            int v = q.front();q.pop();
            dp[v+a[j]]=1;
            dp[v-a[j]]=1;
        }
        dp[15000+a[j]]=1;
        dp[15000-a[j]]=1;
    }
    cin>>t;
    while(t--) {
        int x;
        cin>>x;
        if(dp[x+15000]) cout<<"Y ";
        else cout<<"N ";
    }
}
