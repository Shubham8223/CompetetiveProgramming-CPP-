#include<bits/stdc++.h>
using namespace std;
int edi(string s1,string s2,int m,int n)
{  if(m==0)
    return n;
   if(n==0)
     return m;
   if(s1[m-1]==s2[n-1])
      return edi(s1,s2,m-1,n-1);
	else 
	return min(edi(s1,s2,m-1,n),min(edi(s1,s2,m,n-1),edi(s1,s2,m-1,n-1)))+1;
}
int edidp(string s1,string s2,int m,int n)
{
	int dp[m+1][n+1];
	for(int i=0;i<=n;i++)
		dp[0][i]=i;
	for(int i=0;i<=m;i++)
		dp[i][0]=i;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
		}
	return dp[m][n];
}

int main()
{  
   cout<<"recursive :"<<edi("saturday","sunday",8,6)<<endl<<"dp soln:"<<edidp("saturday","sunday",8,6);
   return 0;
 }
  
