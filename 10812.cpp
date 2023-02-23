#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a[111];
    cin>>n>>m;
    for (int i = 1; i<=n; i++) a[i]=i;
    while(m--) {
        int x, y, z, b[111];
        cin>>x>>y>>z;
        for (int i = x; i <= y; i++) b[i] = a[i];
        for (int i = x; i <= y; i++) {
            a[i] = b[z++];
            if(z > y) z=x;
        }
    }
    for (int i = 1; i <= n; i++) cout<<a[i]<<" ";
}
