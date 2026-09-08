#include<bits/stdc++.h>
using namespace std;

int heap_push(vector<int> *que,data) {
    que.push_back(data);
    int parent,child = que.size();
    while(child != 1) {
        if(child%2 == 0)
            parent = child/2;
        else
            parent = (child-1)/2;
        if(que[parent] > que[child]) {
            swap(que[parent],que[child]);
            child = parent;
        }
    }
}

int heap_top(vector<int> que) {
    return que[1];
}

int heap_pop(vector<int> que) {
    que[1] = que.back();
    que.pop_back();

}
int heap_push(vector<int> *que,data)
int main() {
    vector<int> thepi_que;
    thepi_que.push_back(0);
    int n,tmp;
    cin >> n;
    while(n--){
        cin >> tmp;
        thepi_que[n] = tmp;
    }
}
