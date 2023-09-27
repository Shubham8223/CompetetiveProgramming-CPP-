#include<bits/stdc++.h>
using namespace std;
class node
{  public:
     node* left;
	 node* right;
	 int value;
	 node(int n)
	 {  value=n;
	    left=NULL;
		right=NULL;
	 }
	 node()
	 {   value=0;
	     left=NULL;
		 right=NULL;
	 }
	 node* addnode(int v,node* root)
	 {   node *temp=new node(v);
	     if(root==NULL)
		 { return temp;
		 }
	     node *c=NULL,*pred=root;
		 while(pred!=NULL)
		 {
		  c=pred;
		  if(v>pred->value)
		   {
		       pred=pred->right;
		   }
		  else if(v<pred->value)
		   {
		       pred=pred->left;
		   }
		 }
		 if(c->value<v)
		  c->right=temp;
		 else
		  c->left=temp;
		 return root;
     }
	 void ino(node* root)
	 { if(root!=NULL)
		 {
			 ino(root->left);
			 cout<<root->value<<endl;
			 ino(root->right);
		 }
	 }
};
int main()
{
	node b,*d=NULL;
	d=b.addnode(3,d);
	d=b.addnode(4,d);
	d=b.addnode(12,d);
	d=b.addnode(1,d);
	d=b.addnode(76,d);
	b.ino(d);
	return 0;
}
