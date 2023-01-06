#include <bits/stdc++.h>
using namespace std;

char c[55];

int main() {
   scanf("%s", c);
   int val = 0, len = strlen(c), ans = 0, chk = 0, temphap = 0, chkmin=0;
   for (int i = 0; i < len; i++) {
      if(c[i]>='0' && c[i] <= '9') {
         if(chk == 0 && c[i] == '0') continue;
         val = val*10+(int(c[i])-48);
         chk = 1;
      }
      else if(c[i] == '+') {
         if(chkmin == 1) temphap += val;
         else ans += val;
         val = 0; chk = 0;
      }
      else {
         if(chkmin == 0) {ans += val; chkmin = 1;}
         else {ans -= (temphap+val);}
         temphap = 0; val = 0; chk = 0;
      }
   }
   if(chkmin == 1) printf("%d", ans-(temphap+val));
   else printf("%d", ans+val);
}
