#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    string ss;
    cin >> ss;
    int n;
    cin >> n;
    for(int i = n;i < ss.length()-n;i++) {
        cout << ss[i];
    } cout << endl;
}