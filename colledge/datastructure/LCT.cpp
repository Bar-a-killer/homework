#include <iostream>
#include <vector>

using namespace std;

int findc(int u, int v, const vector<int>& tree) {
    while (tree[u] != tree[v]) {
        if (u > v) {
            u = (u-1)/2;
        } else {
            v = (v-1)/2;
        }
    }
    return tree[u];
}
int main() {
    vector<int> tree;
    int tmp;
    while(cin >> tmp) {
        tree.push_back(tmp);
    }
    int u = tree.back();
    tree.pop_back();
    int v = tree.back();
    tree.pop_back();
    int uc = 0, vc = 0;
    for(int i = 0; i < tree.size(); ++i) {
        if(tree[i] == u && !uc) {
            uc = 1;
            u = i;
        }
        if(tree[i] == v && !vc) {
            vc = 1;
            v = i;
        }
    }
    cout << findc(u, v, tree) << endl;

    return 0;
}