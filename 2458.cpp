#include <bits/stdc++.h>
using namespace std;
vector <int> L[501];
vector <int> S[501];
int q[501];
int n, m, ans = 0, tmp = 0;

void dfs_L(int x) {
    if(L[x].empty() == true) return;
    int i, y = L[x].size();
    for (i = 0; i < y; i++) {

        int a = L[x][i];
        if(q[a] == 1) continue;
        q[a] = 1;tmp++;
        dfs_L(a);
    }
}

void dfs_S(int x) {
    if(S[x].empty() == true) return;
    int i, y = S[x].size();
    for (i = 0; i < y; i++) {

        int a = S[x][i];
        if(q[a] == 1) continue;
        q[a] = 1;tmp++;
        dfs_S(a);
    }
}

int main() {
    int i, a, b, j;
    scanf("%d %d", &n, &m);
    for (i = 1; i <= m; i++){
        scanf("%d %d", &a, &b);
        L[a].push_back(b);
        S[b].push_back(a);
    }
    for (i = 1; i <= n; i++) {
        dfs_L(i);
        for (j = 1; j <= n; j++) q[j] = 0;
        dfs_S(i);
        if(tmp == n-1) ans++;
        tmp = 0;
        for (j = 1; j <= n; j++) q[j] = 0;
    }
    printf("%d", ans);
    return 0;
}
