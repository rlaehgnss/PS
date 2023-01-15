#include <bits/stdc++.h>
using namespace std;

int n, curtime = 1, chk = 0;

void f() {
    if(chk) curtime--;
    else curtime++;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        char c[11];
        int x;
        scanf("%s %d", c, &x);
        if(c[0] == 'H') {
            printf("%d NO\n", curtime);
            if(x == curtime) f();
            else {
                chk = 1-chk;
                f();
            }
        }
        else {
            if(x == curtime) printf("%d YES\n", curtime);
            else printf("%d NO\n", curtime);
            f();
        }
        if(curtime == 13) curtime = 1;
        if(curtime == 0) curtime = 12;
    }
}
