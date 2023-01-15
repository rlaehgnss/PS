#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a[35], ans = 0, cur;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if(i == 1) cur = a[i];
        else {
            if(a[i] == a[i-1]+1) continue;
            else {ans += cur; cur = a[i];}
        }
    }
    printf("%d", ans+cur);
}
