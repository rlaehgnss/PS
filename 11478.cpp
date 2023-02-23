#include <bits/stdc++.h>
using namespace std;

char c[1010];
set<string> st;
string s;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(NULL);
    cin>>s;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            st.insert(s.substr(i, j-i+1));
        }
    }
    cout<<st.size();
}
