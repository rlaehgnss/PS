#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> pq[100001];
int n, x1, x2, minn = 100000001, check[100001] = {0};
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

void dfs(int st, int hap, int maxx) {
    if(st == x2) {
        if(hap-maxx < minn) minn = hap-maxx;
        return;
    }
    if(check[st] == 1) return;
    check[st] = 1;
    int i, p = pq[st].size(), x, y;
    for (i = 0; i < p; i++) {
        x = pq[st][i].first;
        y = pq[st][i].second;
        if(y > maxx) dfs(x, hap+y, y);
        else dfs(x, hap+y, maxx);
    }
    return;
}

int main() {
    int i, a1, a2, a3;
    scanf("%d %d %d", &n, &x1, &x2);
    for (i = 1; i <= n-1; i++) {
        scanf("%d %d %d", &a1, &a2, &a3);
        pq[a1].push_back(make_pair(a2, a3));
        pq[a2].push_back(make_pair(a1, a3));
    }
    for (i = 1; i <= n; i++) {
        sort(pq[i].begin(), pq[i].end(), cmp);
    }
    dfs(x1, 0, 0);
    printf("%d", minn);
    return 0;
}
