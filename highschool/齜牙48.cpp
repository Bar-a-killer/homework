#include<bits/stdc++.h>
using namespace std;
struct Node{
	int val;
	Node *l;
	Node *r;
};

void dfs(Node* n){
	if(n->l!=NULL)
		dfs(n->l);
	if(n->r!=NULL)
		dfs(n->r);
	cout << n->val << endl;
}
void bst(Node* n,Node* cur){
	if (n->val < cur->val) {
        if (cur->l == nullptr) {
            cur->l = n;
            return;
        }
        bst(n,cur->l);
    } else {
        if (cur->r == nullptr) {
            cur->r = n;
            return;
        }
        bst(n,cur->r);
    }
}
int main()
{
	int N,input;
	Node *root = new Node();
	cin >> N;
	cin >> input;
	
    root->val = input;
    root->l = nullptr;
    root->r = nullptr;
    
	vector<Node*> datas;
	datas.resize(N);
	for(int i=0;i<N-1;i++){
		cin >> input;
		datas[i] = new Node();
		datas[i]->val = input;
	    datas[i]->l = nullptr;
	    datas[i]->r = nullptr;
	    bst(datas[i],root);
	}
    dfs(root);
}