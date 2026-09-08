#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
class node {
    public:
    int data;
    vector<node*> link;
    node(int val) {
        data = val;
    }
    void putlink(node* linked) {
        link.push_back(linked);
    }
};
node* vector_empty(vector<node*> vec) {
    for(auto i : vec) {
        if(i != nullptr) {
            return i;
        }
    }
    return nullptr;
}
void dfs(vector<node*> &nodes, node* start) {
    stack<node*> s;
    s.push(start);
    while(!s.empty()) {
        node* curr = s.top();
        s.pop();
        if(nodes[curr->data] == nullptr) {
            continue;
        }
        cout << curr->data << ' ';
        nodes[curr->data] = nullptr;
        for(auto i : curr->link) {
            if(nodes[i->data] != nullptr) {
                s.push(i);
            }
        }
    }
}
int main() {
    vector<node*> nodes(100, nullptr);
    int tmp1, tmp2;
    while(cin >> tmp1 >> tmp2) {
        if(nodes[tmp1] == nullptr) {
            nodes[tmp1] = new node(tmp1);
        }
        if(nodes[tmp2] == nullptr) {
            nodes[tmp2] = new node(tmp2);
        }
        nodes[tmp1]->putlink(nodes[tmp2]);
        nodes[tmp2]->putlink(nodes[tmp1]);
    }
    node* start = vector_empty(nodes);
    while(start != nullptr) {
        dfs(nodes, start);
        cout << endl;
        start = vector_empty(nodes);
    }
}