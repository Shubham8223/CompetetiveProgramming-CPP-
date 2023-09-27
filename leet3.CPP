#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> &a,pair<int,int> &b)
{  return a.first<b.first;
}
int lis(vector<pair<int,int>> &a,int n)
{
	int li[n];
	li[0]=1;
	for(int i=1;i<n;i++)
	{   li[i]=1;
		for(int j=0;j<i;j++)
		{  if(a[i].first>a[j].second)
			 li[i]=max(li[i],li[j]+1);
		 
		}
	}
	 return *max_element(li,li+n);
}
int main()
{ vector<pair<int,int>> a;
int ar1[]={5,39,15,27,50};
int ar2[]={24,60,28,40,90};
for(int i=0;i<5;i++)
{
	a.push_back(make_pair(ar1[i],ar2[i]));
}
  sort(a.begin(),a.end(),cmp);
   for(auto it:a)
  {
	  cout<<it.first<<" "<<it.second<<endl;
  }
 cout<<lis(a,5)<<endl;
  return 0;
}