#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
string s="";
int lcsmemo(string s1,string s2,int m,int n)
{   if(dp[m][n]!=-1)
	return dp[m][n];
    else if(m==0||n==0)
	{
		dp[m][n]=0;
		return 0;
	}
   else
   {	if(s1[m-1]==s2[n-1])
	   {	  
			  return 1+lcsmemo(s1,s2,m-1,n-1);
       }
		else
		return max(lcsmemo(s1,s2,m-1,n),lcsmemo(s1,s2,m,n-1));
   }
   return dp[m][n];
}
int lcs(string s1,string s2,int m,int n)
{
	int tab[m+1][n+1];
	for(int i=0;i<n;i++)
		tab[0][i]=0;
	for(int i=0;i<m;i++)
		tab[i][0]=0;
	for(int i=1;i<=m;i++)
	{	for(int j=1;j<=n;j++)
		{
			if(s1[i-1]==s2[j-1])
			{   
				tab[i][j]=tab[i-1][j-1]+1;
			}
			else
				tab[i][j]=max(tab[i-1][j],tab[i][j-1]);
		}
	}
	return tab[m][n];
}
		
int main()
{
	string s1="AXYBCZ", s2="BANCZ";
	
	int n = 6, m = 5;
	
	memset(dp,-1,sizeof(dp));
	
	cout<<lcsmemo(s1,s2,n,m)<<endl;
	cout<<lcs(s1,s2,n,m);
	return 0;
}
	