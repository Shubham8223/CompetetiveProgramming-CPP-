#include<bits/stdc++.h>
using namespace std;
int coin(vector<int> &c,int n,int sum)
{   if(sum==0)
    return 1;
    if(n==0)
    return 0;
	int res=coin(c,n-1,sum);
	if(c[n-1]<=sum)
	{
	    res+=coin(c,n,sum-c[n-1]);
	}
	return res;
}
int coindp(vector<int> &c,int n,int sum)
{
	int dp[n+1][sum+1];
	for(int i=0;i<=n;i++)
	{   dp[i][0]=1;
    }
	for(int i=0;i<=sum;i++)
	{
		dp[0][i]=0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=sum;j++)
		{
		    dp[i][j]=dp[i-1][j];
			if(c[i-1]<=j)
			 dp[i][j]+=dp[i][j-c[i-1]];
		}
	return dp[n][sum];
}
int main()
{  vector<int> v={2,5,3,6};
   cout<<"recursive :"<<coin(v,4,10)<<endl<<"dp soln:"<<coindp(v,4,10);
   return 0;
 }
  
