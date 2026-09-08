#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;

        unordered_set<int> c;
        int i = 1;
        int ci = 1;
        while (true) {
            int next_ci;
            string si = to_string(ci);
            string t = to_string(i + 1);
            string si_plus_1 = si + t;
            next_ci = stoi(si_plus_1);
            if (c.count(ci - next_ci % x)) {
                cout << "YES" << endl;
                cout << ci << " " << next_ci << endl;
                break;
            }
            c.insert(ci - next_ci % x);
            ci = next_ci;
            i++;
        }
        if (i == 1) {
            cout << "NO" << endl;
        }
    }

    return 0;
}