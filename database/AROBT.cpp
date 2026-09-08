#include <iostream>
using namespace std;
typedef struct node{
    int left;
    int right;
    int val;
} node;

int main() {
    node nodes[1000] = {0};
    int k = 1;
    for(int i = 0; i < 100; i++) {
        nodes[i].left = k++;
        nodes[i].right = k++;
    }
    int tmp;
    cin >> tmp;
    int left, right, val;
    while(cin >> val >> left >> right) {
        if(nodes[0].val == 0) {
            nodes[0].val = val;
        }
        for(int i = 0; i < 1000; i++) {
            if(nodes[i].val == val) {
                nodes[nodes[i].left].val = left;
                nodes[nodes[i].right].val = right;
                break;
            }
        }
    }
    int i = 0;
    int cnt = 0;
    while(cnt < tmp) {
        cout << nodes[i].val << " ";
        if(nodes[i].val != 0) {
            cnt++;
        }
        i++;
    }
}