#include<bits/stdc++.h>
using namespace std;
typedef vector v;
vector<int> dup(vector<int> v)
{	int w=0;
	for(int i=1;i<v.size();i++)
	{
		if(v[i]!=v[w])
		{	v[w+1]=v[i];
			w++;
		}
	}
	v.resize(w+1);
	return v;
}
void lead(vector<int> v)
{	cout<<v[v.size()-1]<<endl;
	int cl=v[v.size()-1];
	for(int i=v.size()-2;i>=0;i--)
	{
			if(v[i]>cl)
			{	cout<<v[i]<<endl;
				cl=v[i];
			}
	}
}
void freq(vector<int> v)
{ int f=1;
	for(int i=1;i<v.size();i++)
		{ if(v[i]==v[i-1])
			f++;
		  else
		  {
			  cout<<v[i-1]<<" "<<f<<endl;
			  f=1;
		  }
		}
	cout<<v[v.size()-1]<<" "<<f;
}
int maxc(vector<int> v)
{	int res,i=0,max1=0;
	while(i<v.size())
	{
		res=0;
		while(v[i]==1&&i<v.size())
		{
			res++;
			max1=max(max1,res);
			i++;
		}
		i++;
	}
	return max1;
}
int maxs(vector<int> v) 
{	int res=0,max1=v[0],i=0,w=0;
	while(i<v.size())
	{
		res+=v[i];
		if(res<max1)
		{	res-=v[w];
			w++;
		}
		max1=max(res,max1);
		i++;
	}
	return max1;
}
void nfib(int n,int k)
{
		vector<int> v(n);
		v[k-1]=1;
		v[k]=1;
		int s=1,w=0;
		for(int i=k+1;i<n;i++)
		{   s+=(v[i-1]-v[w]);
			w++;
			v[i]=s;
		}
		for(int i:v)
			cout<<i<<endl;
}
int firstocc(vector<int> v,int x)
{	int m,l=0,h=v.size()-1;
	while(l<=h)
	{ m=(l+h)/2;
	if(v[m]==x&&(v[m]!=v[m-1]||v[m]==0))
		return m;
	if((v[m]==x&&v[m]==v[m-1])||v[m]>x)
		h=m-1;
	else
		l=m+1;
	}
	return -1;
}

int counocc(vector<int> v,int x,int l,int h)
{  if(l>h)
	return 0;
 int m=(l+h)/2;
 if(v[m]>x)
	 return counocc(v,x,l,m-1);
else if(v[m]<x)
	 l=m+1;
 
}
void frequ(vector<int> v)
{
	int res=v[0],fre=1;
	for(int i=1;i<v.size();i++)
	{
		if(v[i]!=res)
		{
			cout<<res<<":"<<fre<<endl;
			fre=1;
			res=v[i];
		}
		else
		fre++;
	}
	cout<<v.back()<<":"<<fre;
}
/*void cons(vector<int> v)
{
	int max1=-1,i=0;
	while(i<v.size())
	{   int p=0;
		while(v[i]==1)
		
			p++;
			i++;
		}
		max1=max(max1,p);
		i++;
	}
	cout<<max1;
}*/
bool givs(vector<int> v,int s)
{ int max1=v[0],k=0;
	for(int i=1;i<v.size();i++)
	{	if(max1==s)
		{
			return true;
		}
		while(max1>s && k<i-1)
		{
			max1-=v[k];
			k++;
		}
		max1+=v[i];
	}
	if(max1==s)
		return true; 
	else
		return false; 
}
void snake(vector<vector<int>> v)
{ for(int i=0;i<v.size();i++)
	{
		if(i%2==0)
		{	for(int j=0;j<v[0].size();j++)
			{	cout<<v[i][j];
			}
		}
		else
		{	for(int j=v[0].size()-1;j>=0;j--)
			{	cout<<v[i][j];
			}
		}
	}
}
struct node
{   int x;
	node* next;
	node(int x)
	{  
		this->x=x;
		this->next=NULL;
	}
}   
bool searchmat(v<v<int>> arr,int x)
{	int c=arr[0].size(),r=arr.size(); 
	int i=0,j=c-1;
		while(i<r&&j>=0)
		{   if(arr[i][j]==x)
				return 1;
			else if(a[i][j]<x)
				i++;
			else
				j--;
		}
		
		return 0;
}
	
struct node
{
		int data;
		node* left;
		node* right;
		node(int x)
		{	this->data=x;
			left=NULL;
			right=NULL:
		}
};
void lvl		
int main()
{ 	vector<vector<int>> v={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	snake(v);
	return 0;
}
