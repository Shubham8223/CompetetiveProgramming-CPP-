#include<bits/stdc++.h>
using namespace std;
#define n 4
bool issafe(int sol[n][n],int i,int j)
{    int u=i-1;
	for(int k=j-1;k>=0;k--)
	{	if(sol[i][k]==1)
		return false;
	    if(sol[u][k]==1 && u>=0)
		{	
			return false;
		}
		u--;
		
    }
	for(int l=i+1,m=j-1;l<n && m>=0;l++,m--)
	{
		if(sol[l][m]==1)
			return false;
	}
	return true;
}
bool solver(int sol[n][n],int col)
{	if(col==n)
	return true;
	for(int i=0;i<n;i++)
	{
		if(issafe(sol,i,col))
		{   sol[i][col]=1;
			if(solver(sol,col+1))
			{
					return true;
			}
			sol[i][col]=0;
		}
	}
	return false;
}
int main()
{	int sol[n][n];
	memset(sol,0,sizeof(sol));
	if(solver(sol,0))
	{
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++)
		{	for(int j=0;j<n;j++)
			{
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else
		cout<<"NO";
 return 0;
}
		 
	