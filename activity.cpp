#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> a,pair<int,int> b)
{
	return a.second<b.second;
}
		
int activity(pair<int,int> a[],int n)
{     sort(a,a+n,comp);
      int act=1;
	  int prev=0;
	  for(int i=1;i<n;i++)
	  {
		  if(a[i].first>=a[prev].second)
		  {  act++;
	         prev=i;
		  }
	  }
	  return act;
}

     
int main()
{  	 int n = 3;
	 pair <int, int> arr[] = {make_pair(12, 25), make_pair(10, 20), make_pair(20, 30)};
	 cout<<activity(arr, n); 
	return 0;
}