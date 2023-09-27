#include<bits/stdc++.h>
using namespace std;
#define vec vector<int>
class edge
{
	int w;
	int v;
	public:
	edge(int v,int w)
	{
		this->w=w;
		this->v=v;
	}
	int getw()
	{
	return w;
	}
	int getv()
	{
	return v;
    }
};
class graph
{
	int ver;
	list<edge>* adj;
	public:
	graph(int ver)
	{
		this->ver=ver;
		adj=new list<edge>[ver];
	}
	void add(int x,int y,int w)
	{	edge e(y,w);
		adj[x].push_back(e);
	}
	void topo(vector<bool> vis,int s,stack<int> st)
	{		vis[s]=true;
			for(auto it:adj[s])
				{	if(!vis[it.getv()])
						{	
							topo(vis,it.getv(),st);
						}
				}
			st.push(s);
	}
	vec shortest(int tar)
	{	stack<int> st;
		vector<bool> vis;
		fill(vis.begin(),vis.end(),false);
		topo(vis,tar,st);
		vec dis;
		fill(dis.begin(),dis.end(),INT_MAX);
		dis[tar]=0;
		while(!st.empty())
		{	int u=st.top();
			st.pop();
			for(auto val:adj[u])
			{	dis[val.getv()]=min(dis[u]+val.getw(),dis[val.getv()]);
			}
		}
		return dis;
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