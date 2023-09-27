#include<bits/stdc++.h>
using namespace std;
template<typename t,typename t2>
t gc(t a,t2 b) 
{  if(a==0)
	return b;
   if(b==0)
	return a;
   if(a>b)
	  return gc(b,a%b);
   else
	  return gc(a,b%a);
} 
template<typename t,typename t2,typename...args>
t gc(t p,t2 q,args...r)
{
   return gc(p,gc(q,r...));
}


int main()
{  cout<<gc(3,6,9,18,90,120);
   return 0;
}
	
	