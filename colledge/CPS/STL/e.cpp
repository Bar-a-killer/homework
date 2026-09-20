#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    string s;
    getline(cin,s);
    
    if(s.size() == 0) {
        cout << "Yes" << endl;
        return;
    }
    stack<char> st;
    st.push(0);
    for(char c:s) {
        char t = st.top();
        if(c == ')' && t == '(') st.pop();
        else if(c == ']' && t == '[') st.pop();
        else if(c == ')' || c == ']') {
            cout << "No" << endl;
            return;
        } else {
            st.push(c);
        }
    }
    if(st.size() != 1) cout << "No" << endl;
    else cout << "Yes" << endl;
}
signed main() {
    int n;cin >> n;
    cin.ignore();
    while(n--) solve();
}