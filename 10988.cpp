#include <bits/stdc++.h>
using namespace std;

int main() {
    char c[111];
    scanf("%s", c);
    int cnt = 0, len = strlen(c);
    for (int i = 0; i < len/2; i++) {
        if(c[i]!=c[len-1-i]) cnt=1;
    }
    cout<<1-cnt;
}
