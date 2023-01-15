#include <bits/stdc++.h>
using namespace std;

struct data{
    char c[11];
    int v;
}a[101010];
int n, s=0,b=0,l=0,p=0;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s %d", a[i].c, &a[i].v);
        if(a[i].c[0] == 'S') s += a[i].v;
        if(a[i].c[0] == 'B') b += a[i].v;
        if(a[i].c[0] == 'L') l += a[i].v;
        if(a[i].c[0] == 'P') p += a[i].v;
    }
    if(s == 5 || b == 5 || l == 5 || p == 5) printf("YES");
    else printf("NO");
}
