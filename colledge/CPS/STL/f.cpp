#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(string a,string b) {
    return a+b < b+a;
}
signed main() {
    int n;
    cin >> n;
    vector<string> d(n);
    for(int i = 0;i < n;i++) {
        cin >> d[i];
    }
    sort(d.begin(),d.end(),cmp);
    for(int i = 0;i < n;i++) {
        cout << d[i];
    }
    cout << endl;
}