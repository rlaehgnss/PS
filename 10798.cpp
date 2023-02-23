#include <bits/stdc++.h>
using namespace std;

int main() {
    char c[5][20];
    for (int i = 0; i < 5; i++) scanf("%s", c[i]);
    int len[5], maxx=0;
    for (int i = 0; i < 5; i++) {
        len[i]=strlen(c[i]);
        maxx = max(maxx, len[i]);
    }
    for (int i = 0; i < maxx; i++) {
        for (int j = 0; j < 5; j++) {
            if(len[j]<=i) continue;
            printf("%c", c[j][i]);
        }
    }
}
