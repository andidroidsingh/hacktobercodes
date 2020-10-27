#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	Node(int data)
	{
		this->value = data;
		this->left = this->right = NULL;
	}
};


Node *makeTree(Node *root, int arr[], int i, int n)
{
	if(i<n)
	{
		Node *temp = new Node(arr[i]);
		temp->left = makeTree(temp, arr, 2*i+0, n);
		temp->right = makeTree(temp, arr, 2*i+1, n);
		root = temp;
	}
	return root;
}
void inorder(Node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int main()
{
	int n;
	cout<<"Enter the number of elements\n";
	cin>>n;

	Node *root;

	cout<<"Enter  the numbers\n";
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	root = makeTree(root, arr, 0, n);
	inorder(root);
	return 0;
}
