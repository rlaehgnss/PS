#include <bits/stdc++.h>
using namespace std;

int k, a[15][2];

int main() {
    int x = 0, y = 0;
    scanf("%d", &k);
    for (int i = 1; i <= 6; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
        if(a[i][0] <= 2) x = max(x, a[i][1]);
        else y = max(y, a[i][1]);
        a[i+6][0] = a[i][0];
        a[i+6][1] = a[i][1];
    }
    for (int i = 2; i <= 8; i++) {
        if((a[i][1]==x&&a[i-1][1]==y) || (a[i][1]==y&&a[i-1][1]==x))continue;
        if((a[i][0] <= 2 && a[i][1] == x) || (a[i][0] > 2 && a[i][1] == y)) {
            if(a[i][0] <= 2) {
                printf("%d", (x*y-(x-a[i+2][1])*(y-a[i-1][1]))*k);
                break;
            }
            else {
                printf("%d", (x*y-(x-a[i-1][1])*(y-a[i+2][1]))*k);
                break;
            }
        }
    }
}
