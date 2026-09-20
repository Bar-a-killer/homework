#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<pair<int,string> > d(n);
    for(int i = 0;i < n;i++) {
        string s;int n;
        cin >> s >> n;
        d[i].first = n;
        d[i].second = s;
    }
    sort(d.begin(),d.end());
    cout << d[n-2].second << endl;

}