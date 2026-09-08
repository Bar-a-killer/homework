#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int x,q;
    cin >> x >> q;
    priority_queue<int,vector<int>,greater<int>> up;
    priority_queue<int> down;
    up.push(x);
    down.push(-1);
    while(q--) {
        int a,b;
        cin >> a >> b;
        up.push(b);
        if(up.top() < down.top()) {
            up.push(down.top());down.push(up.top());
            up.pop();down.pop();
        }
        up.push(a);
        if(up.top() < down.top()) {
            up.push(down.top());down.push(up.top());
            up.pop();down.pop();
        }
        down.push(up.top());up.pop();
        cout << up.top() << endl;
    }
}