#include<bits/stdc++.h>
using namespace std;
template<typename t1,typename t2>
t1 getmin(t1 a,t2 b)
{ return min(a,b);
}
template<typename t1,typename t2,typename...args>
t1 getmin(t1 a,t2 b,args...r)
  { return getmin(a,getmin(b,r...));
  }
 int mincoin(vector<int> c,int n,int val)
 {
   if(val==0)
   return 0;
   int res=INT_MAX;
   for(int i=0;i<n;i++)
   {  if(c[i]<=val)
      {  int sub=mincoin(c,n,val-c[i]);
	     if(sub!=INT_MAX)
		  res=getmin(res,sub+1);
	  }
   } 
   return res;
 }
 int mincoindp(vector<int> c,int n,int val)
 {
	 int dp[val+1];
	   dp[0]=0;
	   for(int i=1;i<=val;i++)
	   { dp[i]=INT_MAX;
	   }
	   for(int i=1;i<=val;i++)
	   {  
		   for(int j=0;j<n;j++)
		   {  
			   if(c[j]<=i)
			   { int f=dp[i-c[j]];
			     if(f!=INT_MAX)
			     dp[i]=min(dp[i],f+1);
			   }
		   }
	   }
	   return dp[val];
 }
		   
 int main()
 { cout<<"recursion :"<<mincoin({9,6,5,1},4,11)<<endl<<"dp soln:"<<mincoindp({9,6,5,1},4,11);
   return 0;
 }