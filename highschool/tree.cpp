#include<bits/stdc++.h>
using namespace std;

int arr[100];
/*class Node
{
	int key;
	Node* left=NULL;
	Node* right=NULL;
	Node (int key)
	{
		this->key=key;
		this->left=NULL;
		this->right=NULL; 
	}
	

};
class Linklist
{
	Node* root;
	
	Linklist()
	{
		this->root=NULL;
	}
	
	inseart
};*/


class Node{
	public:
		int m;
		int num;
		Node *right=NULL;
		Node *left=NULL;
};
vector<Node> ms(1000000);
int collect(Node* root)
{
	if(root->m!=-1)
		return root->m;
	else if(root->left->m==-1&&root->right->m==-1)
	{
		//cout << collect(root->left)+collect(root->right) << endl;
		return collect(root->left)+collect(root->right);
	}
		
	else if(root->left->m==-1)
	{
		return root->right->m+collect(root->left);
	}
	else if(root->right->m==-1)
	{
		return root->left->m+collect(root->right);
	}
	
	else 
	{ 
		//cout << root->left->m + root->right->m << endl;
		return root->left->m+root->right->m;
	}
}

Node* search(Node* root)
{
	//printf("\n");
	if(root->m >=0)
	{
		//printf("a");
		return root;
	}
		
	/*if(root->left->m >= 0 && 0 <= root->right->m)
	{
		if(root->left->m<=root->right->m)
			return root->left;
		if(root->left->m > root->right->m)
			return root->right;
	} */
	if(collect(root->left)<=collect(root->right))
	{
		return search(root->left);
	}
	else
	{
		return search(root->right);
	}
	
}

int main()
{
	
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m,tmp,tmp1,tmp2;
	Node* tmptr;
	cin >> n >> m;
	for(int i=1;i<=2*n-1;i++)
	{
		if(i<n)
			ms[i].m=-1;
		else
			cin >> ms[i].m;
		ms[i].num=i;
	}
	for(int i=0;i<m;i++)
	{
		cin >> arr[i];
	}
	for(int i=0;i<n-1;i++)
	{
		cin >> tmp >> tmp1 >> tmp2;
		ms[tmp].left=&ms[tmp1];
		ms[tmp].right=&ms[tmp2];
	
	}
	
	Node* first=&ms[1]; 
	for(int i=0;i<m;i++)
	{
		
		tmptr=search(first);
		//cout << "c" << endl;
		tmptr->m+=arr[i];

		printf("%d ",tmptr->num);
	}
	
} 
