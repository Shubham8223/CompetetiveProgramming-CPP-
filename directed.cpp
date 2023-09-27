#include<bits/stdc++.h>
using namespace std;
#define vec vector<int>
class edge
{
	int w;
	int id;
	public:
	edge(int id,int w)
	{
		this->id=id;
		this->w=w;
	}
	int getw()
	{ return w;
	}	
	int getid()
	{
		return id;
	}
};
class	graph
{	int v;
	list<edge> *li;
	public:
	graph(int v)
	{	this->v=v;
		li=new list<edge>[v];
	}
	void add(int u,int v,int w)
	{	edge e(v,w);
		li[u].push_back(e);
	}
	vec topo()
	{	
		vec ind(v,0);
		for(int i=0;i<v;i++)
		{
			for(auto x:li[i])
			{
				ind[x.getid()]++;
			}
		}
		queue<int> q;
		for(int i=0;i<v;i++)
		{
			if(ind[i]==0)
				q.push(i);
		}
		vec sol;
		while(q.empty()==false)
		{
			int u=q.front();
			sol.push_back(u);
			q.pop();
			for(auto x:li[u])
			{
				ind[x.getid()]--;
				if(ind[x.getid()]==0)
					q.push(x.getid());
			}
		}
		return sol;
	}
	void print()
	{
		for(int i=0;i<v;i++)
		{	for(auto x:li[i])
			{
				cout<<x.getid()<<" ";
			}
			cout<<endl;
		}
	}
	void topo(bool vis[],stack<int> st,int s)
	{
		vis[s]=true;
		for(auto x: li[s])
		{
			if(!vis[x.getid()])
			{	vis[x.getid()]=true;
				topo(vis,st,x.getid());
			}
		}
		st.push(s);
	}
	void inittopo(stack<int> st,int s)
	{	bool vis[v];
        fill(vis,vis+v,false);
		topo(vis,st,s);
	}

	vec shortest(int x)
	{	vec len(v);
		fill(len.begin(),len.end(),INT_MAX);
		len[x]=0;
		vec sol=topo();
		for(int i=0;i<v;i++)
		{ 	int s=sol[i];	
			for(auto it: li[s])
			{
				if(len[s]!=INT_MAX)
				{
					len[it.getid()]=min(len[it.getid()],len[s]+it.getw());
				}
			}
		}
		return len;
	}
		
};
int main() 
{ 
	graph g(6); 
	g.add(0, 1, 2); 
	g.add(0, 4, 1); 
	g.add(1, 2, 3); 
	g.add(4, 2, 2); 
	g.add(4, 5, 4); 
	g.add(2, 3, 6); 
	g.add(5, 3, 1);
	vec sol=g.shortest(0);
	for(auto x: sol)
		cout<<x<<" "; 
	return 0; 
} 
		
	
	
	