#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(NULL);
    int x1, x2, x3, y1, y2, y3, ansx, ansy;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    if(x1==x2) ansx = x3;
    else if(x2==x3) ansx = x1;
    else ansx = x2;

    if(y1==y2) ansy = y3;
    else if(y2==y3) ansy = y1;
    else ansy = y2;
    cout<<ansx<<" "<<ansy;
}
