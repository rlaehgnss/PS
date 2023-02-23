#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a[111]={0};
    cin>>n>>m;
    for (int i = 1; i <= n; i++) a[i] = i;
    for (int i = 1;i <= m; i++) {
        int x, y, tmp;
        cin>>x>>y;
        tmp = a[x];
        a[x] = a[y];
        a[y] = tmp;
    }
    for (int i = 1; i <= n; i++) cout<<a[i]<<" ";
}
