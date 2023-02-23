#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    priority_queue<int, vector<int>, greater<int>> pq, pq2;
    while(1) {
        cin>>n;
        if(n==-1) break;
        for (int i = 1; i*i<=n; i++) {
            if(n%i==0) {
                pq.push(i);
                if(i!=n/i && i!=1)pq.push(n/i);
            }
        }
        int s = 0;
        while(!pq.empty()) {
            int c = pq.top();
            s += c;
            pq2.push(c);
            pq.pop();
        }
        if(s == n) {
            printf("%d = ", n);
            while(1) {
                int c = pq2.top();
                printf("%d", c);
                pq2.pop();
                if(pq2.empty()) break;
                printf(" + ");
            }
        }
        else printf("%d is NOT perfect.", n);
        printf("\n");
        while(!pq2.empty()) pq2.pop();
    }
}
