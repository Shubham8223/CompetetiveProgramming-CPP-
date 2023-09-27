#include<bits/stdc++.h>
using namespace std;
#define n 4 
bool issafe(int i,int j,int a[n][n])
	{
		if(i<n	&&	j<n	&&	a[i][j]==1)
			return true;
		return false;
	}
	
bool solver(int i,int j,int a[n][n],int b[n][n])
{  if(i==n-1&&j==n-1)
	{	b[i][j]=1;
		return true;
	}
   
	 if(issafe(i,j,a))
	   {	if(solver(i+1,j,a,b))
				{		
						b[i][j]=1;
						return true;
				}
				else if(solver(i,j+1,a,b))
				{
					b[i][j]=1;
					return true;
				}
			else
				{	b[i][j]=0;
					return false;
				}
	   }
	   else
	   { 	b[i][j]=0;
		   return false;
	   }
}		

int main()
{   int maze[n][n] = { { 1, 0, 1, 0 }, 
                       { 1, 1, 1, 1 }, 
                       { 0, 0, 0, 1 }, 
                       { 1, 1, 1, 1 } };
	int sol[n][n]= {  { 0, 0, 0, 0 }, 
                       { 0, 0, 0, 0 }, 
                       { 0, 0, 0, 0 }, 
                       { 0, 0, 0, 0 } };
	
  if(solver(0,0,maze,sol))
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
			   
  	
	