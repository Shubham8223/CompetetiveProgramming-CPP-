#include<bits/stdc++.h>
using namespace std;
#define v vector<int>
v div(string s)
{ int i=0;
  v a,b;
  while(i<s.length())
  { int j;
   j=s[i]-'0';
   a.push_back(j);
   i++;
  }
  i=0; 
  int q,r=0;
  while(i<s.length())
  {   int u=r*10+a[i];
      q=u/2;
	  r=u%2;
	  b.push_back(q); i++;
  }
  return b;
}
int main()
{
   string s;
   getline(cin,s);
   v k=div(s);
   for(auto it:k)
	   cout<<it;
   return 0;
}
   
   
    
	  
	