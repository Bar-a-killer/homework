#include <bits/stdc++.h>
using namespace std;

struct Node {
    string op;
    int k;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Node> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].op >> a[i].k;
    }

    int ans = 0;

    for (int x = 0; x <= m; x++) {
        int cur = x;

        for (auto &t : a) {
            if (t.op == "AND") cur &= t.k;
            else if (t.op == "OR") cur |= t.k;
            else cur ^= t.k;
        }

        ans = max(ans, cur);
    }
    cout << ans << '\n';
}