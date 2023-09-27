#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node* next;
	node()
	{ data=0;
	  next=NULL;
	}	
	node(int x)
	{
		data=x;
		next=NULL;
	}
};
node* sortll(node *h1,node *h2)
{	node* s;
	node* l1;
	node* l2;
	node* e;
	if(h1->data>h2->data)
	{
			s=h2;
			e=s;
			l2=h2->next;
			l1=h1;
	}
	else
	{       s=h1;
			e=s;
			l2=h2;
			l1=h1->next;	
	}
	while(l1!=NULL && l2!=NULL)
	{	if(l1->data>l2->data)
		{	e->next=l2;
			e=l2;
		    l2=l2->next;
		}
		else
		{
			e->next=l1;
			e=l1;
			l1=l1->next;
		}
	}
	if(l1!=NULL)
	{	while(l1!=NULL)
		{
			e->next=l1;
			e=l1;
			l1=l1->next;
		}
	}
	if(l2!=NULL)
	{	while(l2!=NULL)
		{
			e->next=l2;
			e=l2;
			l2=l2->next;
		}
	}
	return s;
}
bool palind(node* h1)
{ list<int> l;
  while(h1!=NULL)
  {
	  l.push_back(h1->data);
	  h1=h1->next;
  }
  while(l.size()!=0)
  { if(l.front()!=l.back())
	  return false;
    l.pop_back();
	l.pop_front();
    if(l.size()==1)
		return true;
  }
  return true;
}
node* rev(node* head,int k)
{ node* curr=head;
  node* prev=NULL;
  int res=0;
 while(curr!=NULL&&res<k)
 {    res++;
	 node* next1= curr->next;
	 curr->next=prev;
	 prev=curr;
	 curr=next1;
 }
 return prev;
}
node* grprev(node* h,int k)
{
	node* h1=NULL;
	fo
	
int main()
{
	node* h1=new node(10);
	h1->next=new node(20);
	h1->next->next=new node(30);
	h1->next->next->next=new node(50);
	h1->next->next->next->next=new node(10);
	node* re=rev(h1,3);
	while(re!=NULL)
	{
		cout<<re->data<<endl;
		re=re->next;
	}
	return 0;
}