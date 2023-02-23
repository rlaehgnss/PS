#include <bits/stdc++.h>
using namespace std;

char c[202020];
int hap[202020][30] = {{0}};

int main() {
    scanf("%s", c);
    int len = strlen(c);
    for (int i = 0;i < len; i++) {
        for (int j = 0; j < 26; j++) {
            hap[i][j] = hap[i-1][j];
        }
        hap[i][int(c[i])-'a']++;
    }
    int n, x, y;
    char q;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf(" %c %d %d", &q, &x, &y);
        printf("%d\n", hap[y][int(q)-'a']-hap[x-1][int(q)-'a']);
    }
}
