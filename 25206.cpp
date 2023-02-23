#include <bits/stdc++.h>
using namespace std;

int main() {
    char c[22][111], d[22][5];
    double s[22], hap1 = 0, hap2 = 0;
    for (int i = 1; i <= 20; i++) {
        scanf("%s", c[i]);
        scanf("%lf", &s[i]);
        scanf("%s", d[i]);
        if(d[i][0] == 'A') {
            if(d[i][1] == '+') hap1+=s[i]*4.5;
            else hap1+=s[i]*4.0;
            hap2+=s[i];
        }
        else if(d[i][0] == 'B') {
            if(d[i][1] == '+') hap1+=s[i]*3.5;
            else hap1+=s[i]*3.0;
            hap2+=s[i];
        }
        else if(d[i][0] == 'C') {
            if(d[i][1] == '+') hap1+=s[i]*2.5;
            else hap1+=s[i]*2.0;
            hap2+=s[i];
        }
        else if(d[i][0] == 'D') {
            if(d[i][1] == '+') hap1+=s[i]*1.5;
            else hap1+=s[i]*1.0;
            hap2+=s[i];
        }
        else if(d[i][0] == 'F') {
            hap2+=s[i];
        }
        else if(d[i][0] == 'P') {
            continue;
        }
    }
    printf("%lf", hap1/hap2);
}
