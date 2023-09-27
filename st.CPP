#include<bits/stdc++.h>
using namespace std;
class node
{	
	int data;
	node* left;
	node *right;
	public:
	node(int k)
	{	this->data=k;
		this->right=this->left=NULL;
	}
};
int width(node* root)
{
		if(root==NULL)
			return 0;
		int ll=width(root->left);
		int rr=width(root->right);
		
		
int main()
{
	
		
	return 0;
}