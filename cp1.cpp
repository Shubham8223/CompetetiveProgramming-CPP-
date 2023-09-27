#include<bits/stdc++.h>
using namespace std;
bool isint(auto a )
{   
	if((double)(a-(int)a)==0.0 && a>0)
		return true;
	return false;
}
int triplet(int n)
{   int count=0;
	for(int i=1;i<=n;i++)
	{ double b=(double)(i*i-1)/2;
      if(isint(b) && b<=n)
	  {
		  double c=(double)(i*i-b);
		  if(isint(c) && c<=n)
		  {	count++;
		  }
	  }
	}
	return count;
}
int main()
{
	cout<<triplet(3)<<endl;
	return 0;
}
		