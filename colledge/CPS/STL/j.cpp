#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int r;cin >> r;
    cin.ignore();
    string s;
    getline(cin,s);
    stack<char> st;
    st.push(0);
    for(char c:s) {
        char t = st.top();
        if(c == ')' && t == '(') st.pop();
        else st.push(c);
    }
    cout << (st.size()-1)/2 << endl;
}
signed main() {
    int n;cin >> n;
    
    while(n--) solve();
}