#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    string s;

    cin >> s;
    sort(s.begin(),s.end());
    string s_copy = s;
    int cnt = 0;
    do {
        cnt++;
    } while(next_permutation(s.begin(),s.end()));
    cout << cnt << endl;
    do {
        cout << s_copy << endl;
    } while(next_permutation(s_copy.begin(),s_copy.end()));
}