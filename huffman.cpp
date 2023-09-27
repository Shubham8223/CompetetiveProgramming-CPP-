#include<bits/stdc++.h>
using namespace std;
struct node
{
	 int fre;
	 char ch;
	 node *left;
	 node *right;
	 node(char cha,int freq,node* l=NULL,node* r=NULL)
	 {
		 ch=cha;
		 fre=freq;
		 left=l;
		 right=r;
	 }
};
struct cmp{

	bool operator()(node* l, node* r)

	{
		return (l->fre > r->fre);
	}
};

node* createcode(priority_queue<node*,vector<node*>,cmp> q)
{ while(q.size()>1)
	{  node *u1=q.top();
        q.pop();
	   node *u2=q.top();
	    q.pop();  
	   node *n1=new node('$',u1->fre+u2->fre,u1,u2);
	   q.push(n1);
	}
	return q.top();
}
void printcode(node *hc,string s)
{ if(hc->ch!='$')
	{
		cout<<hc->ch<<": "<<s<<endl;
		return;
	}
	else
	{ 	printcode(hc->left,s+'0');
		printcode(hc->right,s+'1');
	}
}	
	
int main()
{   char arr[] = { 'a', 'd', 'e', 'f'};
	int freq[] = { 30, 40, 80, 60 };
	int num=4;
	priority_queue<node*,vector<node*>,cmp> q;
	for(int i=0;i<num;i++)
	{   node *n=new node(arr[i],freq[i]);
		q.push(n);
	}
	node* hc=createcode(q);
	printcode(hc,"");
	return 0;
}
		
		 