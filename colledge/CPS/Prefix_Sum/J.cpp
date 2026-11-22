#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n,t;cin >> n >> t;
    vector<int> books;
    books.push_back(0);
    for(int i = 0;i < n;i++) {
        int tmp;cin >> tmp;
        tmp+=books[i];
        books.push_back(tmp);
    }
    int ans = 0;
    for(int i = 0;i < n;i++) {
        int now = books[i];
        auto idx = upper_bound(books.begin(),books.end(),t+now);
        int num = idx - books.begin()-i-1;
        ans = max(ans,num);
    }
    cout << ans << endl;
}
