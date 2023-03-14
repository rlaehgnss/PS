#include <bits/stdc++.h>
using namespace std;

int n, k, a[505050], cnt = 1, ans=-1;

void mg(int l, int mid, int r) {
    int i = l, j = mid+1, t = 1;
    int tmp[505050];
    while(i <= mid && j <= r) {
        if(a[i] <= a[j]) tmp[t++] = a[i++];
        else tmp[t++] = a[j++];
    }
    while(i <= mid) tmp[t++] = a[i++];
    while(j <= r) tmp[t++] = a[j++];
    i = l; t = 1;
    while(i <= r) {
        a[i++] = tmp[t++];
        if(cnt++ == k) ans = a[i-1];
    }
}

void mgst(int l, int r) {
    if(l < r) {
        int mid = (l+r)/2;
        mgst(l, mid);
        mgst(mid+1, r);
        mg(l, mid, r);
    }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(NULL);

    cin>>n>>k;
    for (int i = 1; i <= n; i++) cin>>a[i];
    mgst(1, n);
    cout<<ans;
}
