#include <bits/stdc++.h>
using namespace std;

int n, m, a[1033][1033] = {{0}};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(NULL);

    cin>>n>>m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin>>a[i][j];
            a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    while(m--) {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1]<<"\n";
    }
}
