#include<bits/stdc++.h>
using namespace std;
#define vec vector<int>
static int k=0;
struct graph
{	vec *a;
    int v;
	graph(int vertex)
	{
	     v=vertex;
		 a=new vec[v];
	}
	void print()
	{
		for(int i=0;i<v;i++)
		{
			for(auto x:a[i])
			cout<<x<<" ";
			cout<<endl;
		}
	}
	void add(int v,int u)
	{
	      a[v].push_back(u);
		  a[u].push_back(v);
    }
	void rem(int v,int u)
	{
	    remove(a[v].begin(),a[v].end(),u);
		 remove(a[u].begin(),a[u].end(),v);
	}
	void dfs(bool vis[],int s,int dis[],int low[],int par[],bool art[])
	{   k++;
		vis[s]=true;
		dis[s]=k;
		low[s]=k;
		int chi=0;
		for(auto it:a[s])
		{
			if(!vis[it])
			{	par[it]=s;
		        chi++;
				dfs(vis,it,dis,low,par,art);
				low[s]=min(low[s],low[it]);
				if(par[s]!=-1 && low[it]>=dis[s])
					art[s]=true;
				if(par[s]==-1 && chi>1)
					art[s]=true;
			}
			else if(it!=par[s])
			{
				low[s]=min(low[s],dis[it]);
			}
			
		}
  
	}
	void art()
	{
		int dis[v];
		int low[v];
		int par[v];
		par[0]=-1;
		bool vis[v];
		fill(vis,vis+v,false);
		bool art[v];
		fill(art,art+v,false);
		dfs(vis,0,dis,low,par,art);
		for(int i=0;i<v;i++)
			if(art[i])
			cout<<i<<" ";
		
	
	}
};
int main()
{
	graph g(7);
	g.add(1,0);
	g.add(0,3);
	g.add(3,2);
	g.add(2,1);
	g.add(1,4);
	g.add(4,5);
	g.add(5,6);
	g.add(4,6);
	g.art();
	return 0;
}