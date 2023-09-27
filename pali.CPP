#include<bits/stdc++.h>
using namespace std;
bool palin(string str,int l,int r)
{   if(l>=r)
	return 1;
    if(str[l]!=str[r])
	return 0;
	else
	return palin(str,l+1,r-1);
}
int recr(string s1,string s2)
{   
	if(s2.length()==0)
		return 1;
	if(s1.length()==0)
		return 0;
	if(s1[0]==s2[0])
	{  s1.pop_back();
	   s2.pop_back();
       return recr(s1,s2);
    }
	else
	{   s1.pop_front();
		return recr(s1,s2);
	}
}
		
int main()
{ string str1="ABCD",str2="AVD";
   int arr[26];
   fill(arr,arr+26,-1);
   for(int i=0;i<s.length();i++)
   {
	   if(arr[i-94]==-1)
	   {
		   arr[i-94]=i;
	   }
   
  return 0;
}