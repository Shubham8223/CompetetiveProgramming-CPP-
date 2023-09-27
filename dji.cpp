#include<bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define V 4
vector<int> dijkstra(int g[V][V],int src)
{
	bool vis[V];
	vector<int> dis(V);
	fill(dis.begin(),dis.end(),INT_MAX);
	dis[src]=0;
	for(int i=0;i<V;i++)
	{
		int u=-1;
		for(int j=0;j<V;j++)
		{	if(!vis[j] && (dis[j]<dis[u] || u==-1))
				u=j;
		}
		vis[u]=true;
		for(int k=0;k<V;k++)
		{
			if(g[u][k]!=0 && !vis[k])
			{
				dis[k]=min(dis[k],dis[u]+g[u][k]);
			}
		}
	}
	return dis;
}
int main() 
{ 
	int graph[V][V] = { { 0, 50, 100, 0}, 
						{ 50, 0, 30, 200 }, 
						{ 100, 30, 0, 20 }, 
						{ 0, 200, 20, 0 },}; 

	for(int x: dijkstra(graph,0))	
	{  cout<<x<<" ";
	} return 0; 
} 
