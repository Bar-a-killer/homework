#include <iostream>
using namespace std;
typedef struct node{
    struct node* left;
    struct node*  right;
    int val;
} node;
void inorder(node* root) {
    if(root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
void preorder(node* root) {
    if(root == nullptr) {
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root) {
    if(root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
int main() {
    node* root = new node();
    node* now = root;
    root->left = nullptr;
    root->right = nullptr;
    int left, right;
    node* nodes[1000];
    int nodex_len = 0;
    int val;
    int tmp;
    cin >> tmp;
    while(cin >> val >> left >> right) {
        for(int i=0;i < nodex_len;i++) {
            if(nodes[i]->val == val) {
                now = nodes[i];
                break;
            }
        }
        if(nodex_len == 0) {
            root = now;
            nodes[nodex_len++] = root;
        }
        now->val = val;
        if(left != 0) {
            node* left_node = new node();
            left_node->val = left;
            left_node->left = nullptr;
            left_node->right = nullptr;
            now->left = left_node;
            nodes[nodex_len++] = left_node;
        }
        if(right != 0) {
            node* right_node = new node();
            right_node->val = right;
            right_node->left = nullptr;
            right_node->right = nullptr;
            now->right = right_node;
            nodes[nodex_len++] = right_node;
        }
    }
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    return 0;
}