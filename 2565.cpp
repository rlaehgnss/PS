#include <bits/stdc++.h>
using namespace std;

struct data{
    int a, b;
    bool operator<(const data&r) const{
        return a < r.a;
    }
}l[111];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(NULL);
    int n, lis[111]={0}, ans = 0;;
    cin>>n;
    for (int i = 1; i<=n; i++) cin>>l[i].a>>l[i].b;
    sort(l+1, l+n+1);
    lis[1]=1;
    for (int i = 2; i <= n; i++) {
        lis[i] = 1;
        for (int j = 1; j < i; j++) {
            if(l[i].b>l[j].b) lis[i]=max(lis[i], lis[j]+1);
        }
        ans = max(ans, lis[i]);
    }
    cout<<n-ans;
}
