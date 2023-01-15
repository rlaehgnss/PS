#include <bits/stdc++.h>
using namespace std;

int n, a[101010], m, seg[404040];

void build(int now, int s, int e) {
    if(s == e) {
        seg[now] = s;
        return;
    }
    int lch = now*2, rch = now*2+1, mid = (s+e)/2;
    build(lch, s, mid);
    build(rch, mid+1, e);
    if(a[seg[lch]] <= a[seg[rch]]) seg[now] = seg[lch];
    else seg[now] = seg[rch];
}

void update(int now, int s, int e, int spot, int v) {
    if(spot < s || e < spot) return;
    if(s == spot && spot == e) return;
    int lch = now*2, rch = now*2+1, mid = (s+e)/2;
    update(lch, s, mid, spot, v);
    update(rch, mid+1, e, spot, v);
    if(a[seg[lch]] <= a[seg[rch]]) seg[now] = seg[lch];
    else seg[now] = seg[rch];
 }

int query(int now, int s, int e, int qs, int qe) {
    if(qe < s || e < qs) return 0;
    if(qs <= s && e <= qe) return seg[now];
    int lch = now*2, rch = now*2+1, mid = (s+e)/2;
    int left = query(lch, s, mid, qs, qe);
    int right = query(rch, mid+1, e, qs, qe);
    if(a[left] <= a[right]) return left;
    else return right;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    a[0] = 1e9+1;
    build(1, 1, n);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        if(x == 1) {a[y] = z; update(1, 1, n, y, z);}
        else printf("%d\n", query(1, 1, n, y, z));
    }

}
