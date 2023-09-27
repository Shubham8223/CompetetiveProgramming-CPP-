#include<bits/stdc++.h>
using namespace std;
int lis(int arr[],int n)
{
	int sol[n];
	sol[0]=1;
	for(int i=1;i<n;i++)
	{	sol[i]=1;
		for(int j=i-1;j>=0;j--)
			{
				if(arr[j]<arr[i])
					sol[i]=max(sol[j]+1,sol[i]);
			}
	}
	return *max_element(sol,sol+n);
}
//now using o(nlogn) solution
int idx(vector<int> ar,int x,int l,int r)
{	while(r>l)
	{ 	int m=(l+r)/2;
			if(ar[m]>=x)
				r=m;
			else
				l=m+1;
	}
	return r;
}	
	
int lis1(int ar[],int n)
{
	vector<int> v;
	v.push_back(ar[0]);
	int len=1;
	for(int i=1;i<n;i++)
	{ if(ar[i]>ar[len-1])
		{
			v.push_back(ar[i]);
			len++;
		}
		else
		{
			auto it=idx(v,ar[i],0,len-1);
			v[it]=ar[i];
		}
	}
	return len;
}			
int dis(int ar[],int n)
{
		int sol[n];
		sol[n-1]=1;
		for(int i=n-2;i>=0;i--)
		{	sol[i]=1;
			for(int j=i+1;j<n;j++)
				{ if(ar[j]<ar[i])
					{  sol[i]=max(sol[j]+1,sol[i]);
				    }
				}
		}
		for(int i=0;i<n;i++)
			cout<<sol[i]<<" ";
	return *max_element(sol,sol+n);
}
bool cmp(pair<int,int> a,pair<int,int> b)
{
	if(a.first!=b.first)
		return a.first<b.first;
	else
		return a.second<b.second;
}
int maxbridge(pair<int,int> *a,int n)
{ 	sort(a,a+n,cmp);
	int sol[n];
	sol[0]=1;
	for(int i=1;i<n;i++)
	{	sol[i]=1;
		for(int j=i-1;j>=0;j--)
			{
				if(a[j].second<a[i].second)
					sol[i]=max(sol[j]+1,sol[i]);
			}
	}
	return *max_element(sol,sol+n);
}
	

	
int main()
{  pair<int,int> a[]={make_pair(8,1),make_pair(1,2),make_pair(4,3),make_pair(3,4),make_pair(2,6),make_pair(6,7),make_pair(7,8),make_pair(5,5)};
	int n = 8;
	cout<<endl<<maxbridge(a,n);
	return 0;
}
	
						
	