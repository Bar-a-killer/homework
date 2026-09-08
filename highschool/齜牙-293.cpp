#include<bits/stdc++.h>
using namespace std;
struct Node{
	//int data;
	vector<Node*> children;
};
void add_node(Node* parent,Node* child){
	parent->children.push_back(child);
	child->children.push_back(parent);
}
int total = 0;
void dfs(Node* node,Node* parent){
	total++;
	//cout << parent->data << "!" << node->data << "--";
	for(auto child:node->children){
		if(child != parent){
			dfs(child,node);
		}
	} 
	//cout << endl;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<Node*> nodes;
		nodes.clear();
		nodes.resize(n);
		for(int i=0;i<n;i++)//{
			nodes[i] = new Node();
			//nodes[i]->data = i;
		//}
		for(int i=0;i<n-1;i++){
			int parent,child;
			cin >> parent >> child;
			add_node(nodes[parent],nodes[child]);
		}
		int min=100000000,ans,tmp=0;
		for(int i=0;i<n;i++){
			for(auto child:nodes[i]->children){
				dfs(child,nodes[i]);
				tmp = max(tmp,total);
				total = 0;
			}
			//cout << tmp << endl;
			if(tmp<min){
				min = tmp;
				ans = i;
			}
			tmp = 0;
		}
		cout << ans << "\n";
		//for(int i=0;i<n;i++){
		//	delete nodes[i];
		//}
	}
}