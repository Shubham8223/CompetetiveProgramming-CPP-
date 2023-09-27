#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b)
{
	return a.second>b.second;
}
int main()
{   int n=5;
	pair<int,int> a[]={make_pair(2,100), make_pair(1,50),make_pair(2,10),make_pair(1,20),make_pair(3,30)};
	sort(a,a+n,cmp);
	int dl=4;
	vector<int> v(n,-1);
	v[a[0].first-1]=a[0].second;
	int jobs=1;
	for(int i=1;i<n;i++)
	{ for(int j=a[i].first-1;j>=0;j--)
		{
			if(v[j]==-1)
			{
				v[j]=a[i].second;
				jobs++;
				break;
			}
		}
       if(jobs==n)
		   break;
	}
	for(auto x:v)
	{
		cout<<x<<endl;
	}
	return 0;
}