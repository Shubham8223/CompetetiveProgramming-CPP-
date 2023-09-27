#include<bits./stdc++.h>
using namespace std;
struct node
{
	node* left;
	int x;
	node* right;
	node()
	{	left=right=NULL;
		x=0;
	}
	node(int r)
	{	left=right=NULL;
		x=r;
	}
};
bool chisum(node* root)
{	if(root==NULL)
		return true;
	if(root->left==NULL&&root->right==NULL) 
		return true;
	int ll=0,rl=0;
	if(root->left)
		ll=root->left->x;
	if(root->right)
		ll=root->right->x;
	return (rl+ll==root->x&&chisum(root->left)&&chisum(root->right));
}
void levtras(node* root)
{	queue<node*> q;
	q.push(root);
	int l=0;
	while(q.empty()==false)
	{
		int c=q.size();
		for(int i=0;i<c;i++)
		{	node* curr=q.front();
			if(i==0)
				cout<<curr->x;
			q.pop();
			if(curr->left)
					q.push(curr->left);
			if(curr->right)
					q.push(curr->right);
		}
		cout<<endl;
	}
}
bool fndpa(vector<int> &v,node* root,int d)
{
	  if(root==NULL)
		  return false;
	  v.push_back(root->x);
	  if(root->x==d)
		  return true;
	  if(fndpa(v,root->left,d)||fndpa(v,root->right,d))
		  return true;
	  v.pop_back();
	  return false;
}
		  
	  
int bal(node* root,bool &r)
{
	if(root==NULL)
		return 0;
	int l=bal(root->left,r);
	int rr=bal(root->right,r);
	if(r==true && abs(l-rr)>1)
		r=false;
	return max(rr,l)+1;
}

				
		
	
int main()
{	node *root=new node(10);
	root->left=new node(20); 
	root->right=new node(30);
	root->left->left=new node(40);
	root->left->right=new node(50);
	vector<int> v;
	cout<<fndpa(v,root,50)<<endl;
	for(auto i:v)
		cout<<i<<endl;
	return 0;
}
	
		
	