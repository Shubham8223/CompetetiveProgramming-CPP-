#include<bits/stdc++.h>
using namespace std;
long long modexp(int ex,int n)
{	if(n==0)
	return 1;
	if(n%2==0)
	return modexp(ex,n/2)*modexp(ex,n/2);
	else
	return modexp(ex,n/2)*modexp(ex,n/2)*ex;
}
	
void powset(string s)
{  
	for(int i=0;i<modexp(2,s.length());i++)
	{	string s1="";
		for(int j=0;j<s.length();j++)
		{  	if(i&(1<<j))
				s1+=s[j];
		}
		cout<<s1<<endl;
	}
}
int main()
{
	powset("abc");
	return 0;
}