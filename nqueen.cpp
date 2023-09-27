#include<bits/stdc++.h>
using namespace std;
#define n 5
bool issafe(int i,int j,int a[n][n])
{   if(i>=n&&j>=n)
	return false;
	int u=i-1;
	for(int l=j-1;l>=0;l--)
	{  
		  if(a[i][l]==1)
			return false;
		  if(a[u][l]==1 && u>=0)
			  return false;
		  u--;
	}
	for(int m=i+1,l=j-1;m<n && l>=0;m++,l--)
	{	if(a[m][l])
		return false;
	}
		
	return true;
}
bool solver(int i,int sol[n][n])
{
	if(i==n)
	{  return true;
    }
	for(int k=0;k<n;k++)
	{
		if(issafe(k,i,sol))
		{    sol[k][i]=1;
			if(solver(i+1,sol))
				return true;
			 sol[k][i]=0;
		}
	}
	return false;
}
int main()
{
	int sol[n][n]= {  { 0, 0, 0, 0, 0},
					  { 0, 0, 0, 0, 0},
					  { 0, 0, 0, 0, 0},
					  { 0, 0, 0, 0, 0},
					  { 0, 0, 0, 0, 0} };					  
                       
	
  if(solver(0,sol))
  {
	  cout<<"yes"<<endl;
	  for(int i=0;i<n;i++)
	  {	for(int j=0;j<n;j++)
		  {
			  cout<<sol[i][j]<<" ";
		  }
		  cout<<endl;
	  }
  }
  else
	  cout<<"no";
  return 0;
}
			  
			
		
		