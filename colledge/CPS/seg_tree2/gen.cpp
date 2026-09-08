#include<bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
    mt19937 rng(atoi(argv[1]));
    auto rnd = [&](int l, int r) { return uniform_int_distribution<int>(l,r)(rng); };
 
    int n = rnd(2, 15);
    int q = rnd(1, 20);
    cout << n << " " << q << "\n";
    for(int i = 0; i < n; i++) {
        cout << rnd(1, 1000000);
        if(i < n-1) cout << " ";
    }
    cout << "\n";
    for(int i = 0; i < q; i++) {
        int op = rnd(1, 3);
        int l = rnd(1, n);
        int r = rnd(l, n);
        cout << op << " " << l << " " << r;
        if(op == 1 || op == 2) cout << " " << rnd(1, 1000000);
        cout << "\n";
    }
}
 