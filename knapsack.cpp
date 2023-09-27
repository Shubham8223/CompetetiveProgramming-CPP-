#include<bits/stdc++.h>
using namespace std;
bool cmp(pair <int, int> a, pair <int, int> b)
{
	double r1 = (a.second /a.first);

	double r2 = (b.second / b.first) ;

	return r1 > r2;
}

int frac(pair<int,int> a[],int n,int w)
{ sort(a,a+n,cmp);
  double prof=0;
  for(int i=0;i<n;i++)
  {
	  if(a[i].first<=w)
	  {
		  prof+=a[i].second;
		  w=w-a[i].first;
	  }
	  else
	  {  prof+=((double)w/a[i].first)*a[i].second;
	      break;
	  }
  }
  return prof;
}
int main()
{
	pair <int, int> arr[] = {make_pair(30,120), make_pair(20,100), make_pair(10,60)};

	int n = 3, W = 50;
	cout<<frac(arr, n,W); 

	return 0;
}