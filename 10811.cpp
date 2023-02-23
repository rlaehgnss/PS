#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a[111]={0};
    cin>>n>>m;
    for (int i = 1; i <= n; i++) a[i] = i;
    for (int i = 1;i <= m; i++) {
        int x, y, tmp;
        cin>>x>>y;
        for (int j = x; j <=(x+y)/2; j++) {
            tmp = a[j];
            a[j] = a[y-(j-x)];
            a[y-(j-x)] = tmp;
        }
    }
    for (int i = 1; i <= n; i++) cout<<a[i]<<" ";
}
