#include<bits/stdc++.h>
using namespace std;
int knap(vector<int> wt,vector<int> v,int w)
  {
      if(w==0)
	    return 0;
	  int res=INT_MIN;
	  int k=0,w1=w;
		for(int i=0;i<wt.size();i++)
		  { if(wt[i]<=w)
		      { k=i;
			    int sub=knap(wt,v,w-wt[i]);
			     if(sub!=INT_MIN)
				   res=max(res,sub+v[i]);
			  }
		  }
		  if(w==w1)
			  return 0;
		  
			  res=res+v[k];
		return res;
 }
 int main()
 {
    cout<<knap({5,4,6,3},{10,40,30,50},10);
	return 0;
}