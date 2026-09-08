#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    vector<Node*> children;
    //int num_descendants=1;
};
void add_node(Node* parent, Node* child) {
    parent->children.push_back(child);
}
int count_children(Node* node) {
    int count = 0;
    //if(node->num_descendants!=1)
    	//return node->num_descendants;
    for (auto child : node->children) {
        count += count_children(child)+1;
    }
    return count;
}
int main()
{
	int T;
	cin >> T;
	int m,n;
	int parent,child;
	vector<Node*> boxes;
	while(T--){
		cin >> m >> n;
		boxes.clear();
        boxes.resize(m+1);
		for(int i=1;i<=m;i++)
		{
			boxes[i] = new Node();
            boxes[i]->data = i;
		}
		cin >> parent >> child;
		add_node(boxes[parent],boxes[child]);
		n--;
		while(n--){
            cin >> parent >> child;
            add_node(boxes[parent],boxes[child]);
        }
        int p,q;
		cin >> p;
		while(p--)
		{
			cin >> q;
			//boxes[q]->num_descendants = count_children(boxes[q]);
			cout << count_children(boxes[q])+1 << endl;
		}
	}

}
