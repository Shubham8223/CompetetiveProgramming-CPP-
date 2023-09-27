#include<bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define V 6
#define v 6
void topo(int g[V][V],bool vis[],int s,stack<int> &st)
	{		vis[s]=true;
			for(int i=0;i<V;i++)
				{	if(!vis[i] && g[s][i]!=0)
						{	
							topo(g,vis,i,st);
						}
				}
			st.push(s);
	}
	
void toporec(int g[V][V],stack<int> &st)
{	bool vis[V];
	for(int i=0;i<V;i++)
	{	if(!vis[i])
			topo(g,vis,i,st);
	}
}

void transpose(int g[v][v])
{
	for(int i=0;i<V;i++)
	{	for(int j=0;j<V;j++)
		{	if(j>i)
			{	int temp=g[i][j];
				g[i][j]=g[j][i];
				g[j][i]=temp;
			}
		}
	}
}

void dfs(int g[V][V],int s,bool vis[V])
{  	cout<<s<<" ";
	vis[s]=true;
	for(int i=0;i<V;i++)
				{	if(!vis[i] && g[s][i]!=0)
						{	
							dfs(g,i,vis);
						}
				}
}
	
void kosaraju(int g[V][V])
{	
	stack<int> st;
	toporec(g,st);
	transpose(g);
	bool vis[V];
	while(!st.empty())
	{
		 int u=st.top();
		 st.pop();
		 if(!vis[u])
		 { dfs(g,u,vis);
	       cout<<endl;
		 }
		
	}
}

int main()
{
	int g[V][V]={{0,1,0,0,0,0},
				 {0,0,1,0,0,0},
				 {0,0,0,1,0,0},
				 {1,0,0,0,1,0},
				 {0,0,0,0,0,1},
				 {0,0,0,0,1,0},};
	kosaraju(g);
	return 0;
}
	
	