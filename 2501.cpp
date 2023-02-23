#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i*i<=n; i++) {
        if(n%i==0) {
            pq.push(i);
            if(i!=n/i)pq.push(n/i);
        }
    }
    if(pq.size() < k) printf("0");
    else {
        int ans, cnt = 1;
        while(1) {
            ans = pq.top(); pq.pop();
            if(cnt==k) break;
            cnt++;
        }
        printf("%d", ans);
    }
}
