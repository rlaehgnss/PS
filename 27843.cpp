#include <bits/stdc++.h>
using namespace std;

int n;
long long a[555], hap[555][555] = {{0}};
vector<pair<long long, pair<int, int>>> sum;

bool f(int index, int l, int r) {
    if(l <= index && index <= r) return true;
    else return false;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            hap[i][j] = hap[i][j-1]+a[j];
            sum.push_back({hap[i][j], {i, j}});
        }
    }
    sort(sum.begin(), sum.end());
    for (int i = 1; i <= n; i++) {
        long long ans = 1e18;
        for (int j = 1; j < sum.size(); j++) {
            bool left = f(i, sum[j-1].second.first, sum[j-1].second.second);
            bool right = f(i, sum[j].second.first, sum[j].second.second);
            if(left != right) ans = min(ans, sum[j].first-sum[j-1].first);
        }
        printf("%lld\n", ans);
    }
}
