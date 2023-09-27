#include<bits/stdc++.h>
using namespace std;
struct node
{
	int key;
	node *left;
	node *right;
	node(int k)
	{
		key=k;
		left=right=NULL;
	}
};
node* ins(node* root,int x)
{
	if(root==NULL)
		return new node(x);
	if(root->key>x)
	{
		root->left=ins(root->left,x);
	}
	else
		root->right=ins(root->right,x);
}
void preord(node *root)
{   node* curr=root;
	stack<node*> st;
	do
	{
		while(curr!=NULL)
		{
			cout<<curr->key<<endl;
			if(curr->right)
				st.push(curr->right);
			curr=curr->left;
		}
		node *t=st.top();
		st.pop();
		curr=t;
	}while(st.empty()==false||curr!=NULL);
}
node* find(node *root,int x)
{
	while(root!=NULL)
	{
		if(root->key==x)
			return root;
		else if(root->key>x)
			root=root->left;
		else
			root=root->right;
	}
	return NULL;
}
int predessor(node *root,int x)
{
	node *t=find(root,x);
	if(t->left)
	{  t=t->left;
		while(t!=NULL && t->right!=NULL)
		{
			t=t->right;
		}
		return t->key;
	}
	else
	{
		node *par=root;
		node *succ=NULL;
		while(par->key!=x)
		{
			if(par->key<x)
			{ 	succ=par;
				par=par->right;
			}
			else
				par=par->left;
		}
		return succ->key;
	}
	return 0;
}
				
		
int succesor(node *root,int x)
{	node *f=find(root,x);
    if(f->right)
	{  f=f->right;
		while(f!=NULL && f->left!=NULL)
		{
			f=f->left;
		}
		return f->key;
	}
	else
	{
		node* par=root;
		node *succ=NULL;
		while(par->key!=x)
		{	if(par->key>x)
			{	succ=par;
				par=par->left;
			}
			else
				par=par->right;
		}
		return succ->key;
	}
	return 0;
}
			
int main()
{
	node *a=new node(15);
	a=ins(a,10);
	a=ins(a,20);
	a=ins(a,8);
	a=ins(a,12);
	a=ins(a,17);
	a=ins(a,25);
	a=ins(a,6);
	a=ins(a,11);
	a=ins(a,16);
	a=ins(a,27);
	cout<<endl<<succesor(a,6)<<endl<<predessor(a,25);
	return 0;
}
	
	
	