#include <iostream>
using namespace std;
typedef struct node {
    int data;
    int kore,low;
    int chcount;
    bool isartic = false;
    struct node *parent;
    struct node *children[10];
} node;
void dfs(node *root, int &depth) {
    if(root == NULL) return;
    depth++;
    root->kore = depth;
    root->low = depth;
    bool isang = false;
    int rootcount = 0;
    for(int i = 0; i < root->chcount; ++i) {
        if(root->children[i] == root->parent) continue;

        if(root->children[i]->kore == -1) {
            root->children[i]->parent = root;
            dfs(root->children[i], depth);
            rootcount++;
            root->low = min(root->children[i]->low, root->low);
            if(root->children[i]->low >= root->kore)
                isang = true;
        } else {
            root->low = min(root->children[i]->kore, root->low);
        }
    }
    if(isang && root->parent != NULL) {
        root->isartic = true;
    } else if(root->parent == NULL && rootcount > 1) {
        root->isartic = true;
    }
}
int  main() {
    node *root = NULL;
    node tmp[1005] = {};
    for(int i = 0; i < 1005; ++i) {
        tmp[i].chcount = 0;
        tmp[i].data = -1;
        tmp[i].kore = -1;
        tmp[i].parent = NULL;
        for(int j = 0; j <10; ++j) {
            tmp[i].children[j] = NULL;
        }
    }
    int now,next;
    
    while(cin >> now >> next) {
        if(root == NULL) {
            root = &tmp[now];
        }
        tmp[now].data = now;
        tmp[next].data = next;
        tmp[now].children[tmp[now].chcount] = &tmp[next];
        tmp[now].chcount++;
        tmp[next].children[tmp[next].chcount] = &tmp[now];
        tmp[next].chcount++;
    }
    int depth = -1;
    dfs(root, depth);
    for(int i = 0; i < 1005; ++i) {
        if(tmp[i].data != -1 && tmp[i].isartic) {
            cout << tmp[i].data << " ";
        }
    }
}