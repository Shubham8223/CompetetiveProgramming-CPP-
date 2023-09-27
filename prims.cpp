#include<bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define V 4
int prims(int g[V][V],int v)
{
	bool vis[v];
	int res=0;
	vector<int> dis(v);
	fill(dis.begin(),dis.end(),INT_MAX);
	dis[0]=0;
	for(int i=0;i<v;i++)
	{
		int u=-1;
		for(int j=0;j<v;j++)
		{	if(!vis[j] && (dis[j]<dis[u] || u==-1))
				u=j;
		}
		vis[u]=true;
		res+=dis[u];
		for(int k=0;k<v;k++)
		{
			if(g[u][k]!=0 && !vis[k])
			{
				dis[k]=min(dis[k],g[u][k]);
			}
		}
	}
	return res;
}
int main() 
{ 
	int graph[V][V] = { { 0, 5, 8, 0}, 
						{ 5, 0, 10, 15 }, 
						{ 8, 10, 0, 20 }, 
						{ 0, 15, 20, 0 },}; 

	cout<<prims(graph,V); 

	return 0; 
} 
