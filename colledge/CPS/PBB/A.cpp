#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> d;
    cout << 1 << '\n';
    
    for(int i = 2;i*i <= n;i++) {
        if(n%i == 0) {
            d.push_back(i);
            d.push_back(n/i);
        }     
    }
    sort(d.begin(),d.end());
    for(int i : d) {
        cout << i << endl;
    }
    if(n!=1)    cout << n << endl;
}
