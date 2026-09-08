#include<iostream>
using namespace std;
typedef struct BSTNode {
    int val;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int v) : val(v), left(nullptr), right(nullptr) {}
} BSTNode;

BSTNode* insert(BSTNode* root, int val) {
    if (!root) {
        return new BSTNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}
void inorder(BSTNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
void preorder(BSTNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
int main() {
    int n;
    cin >> n;
    BSTNode* root = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    return 0;
}