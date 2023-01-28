#include <bits/stdc++.h>
using namespace std;

int n, m, a[10101];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(NULL);
    cin>>n>>m;
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    int l = 1, r = 1, hap = a[1], ans = 0;
    while(1) {
        if(r > n) break;
        if(hap < m) {hap+=a[++r];}
        else if(hap==m) {ans++; hap-=a[l++];}
        else if(hap > m) {
           if(l==r) {l++; hap=a[++r];}
           else {hap-=a[l++];}
        }
    }
    cout<<ans;
}
