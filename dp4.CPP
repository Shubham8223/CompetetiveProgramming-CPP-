#include<bits/stdc++.h>
using namespace std;
int li(vector<int> c,int n)
{  int lis[n];
   lis[0]=1;
   for(int i=1;i<n;i++)
   { lis[i]=1;
    for(int j=0;j<i;j++)
	  { if(c[j]<c[i])
	      lis[i]=max(lis[i],lis[j]+1);
	  }
	}
	return *max_element(lis,lis+n);
}
int idx(int c[],int l,int r,int x)
{
	while(r>l)
	{   int m=(l+r)/2;
		if(c[m]>=x)
			r=m;
		else
			l=m+1;
	}
	return r;
}
int libi(vector<int> c,int n)
{
	int tail[n];
	int len=1;
	tail[0]=c[0];
	for(int i=1;i<n;i++)
	{  if(c[i]>=tail[len-1])
		{ tail[len++]=c[i];
		}
	   else
	   { int g=upper_bound(tail,tail+len,c[i])-tail;
		    tail[g]=c[i];
	   }
	}
	return len;
}
int ld(vector<int> c,int n)
{  int lis[n];
   lis[0]=1;
   for(int i=1;i<n;i++)
   { lis[i]=1;
    for(int j=0;j<i;j++)
	  { if(c[j]>c[i])
	      lis[i]=max(lis[i],lis[j]+1);
	  }
	}
	return *max_element(lis,lis+n);
}

int main()
{  
   cout<<"naive :"<<li({3,4,2,8,10,11,3},7)<<endl<<"bst soln:"<<libi({3,4,2,8,10,11,3},7)<<endl;
   cout<<ld({22,8,2,4,3,6,5,1},8);
   return 0;
 }
  
