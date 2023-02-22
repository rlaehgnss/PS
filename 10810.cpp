#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a[111]={0};
    cin>>n>>m;
    for (int i = 1;i <= m; i++) {
        int x, y, z;
        cin>>x>>y>>z;
        for (int j = x; j <= y; j++) a[j]=z;
    }
    for (int i = 1; i <= n; i++) cout<<a[i]<<" ";
}
