#include <bits/stdc++.h>
using namespace std;

int n;
char a[6566][6566] = {{0}};

void f(int s, int x, int y) {
    for (int i = x+s/3; i < x+2*s/3; i++) {
        for (int j = y+s/3; j < y+2*s/3; j++) a[i][j] = ' ';
    }
    if(s == 3) return;
    for (int i = x; i <= x+2*s/3; i += s/3) {
        for (int j = y; j <= y+2*s/3; j += s/3) f(s/3, i, j);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(NULL);

    cin>>n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) a[i][j] = '*';
    }
    f(n, 1, 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout<<a[i][j];
        cout<<"\n";
    }
}
