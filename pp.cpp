#include<bits/stdc++.h>
using namespace std;
void seg(vector<int>& a)
{ int l=0,h=a.size()-1;
	while(l<=h)
	{	while(a[l]%2==0 && l<a.size())
		{
			l++;
		}
		while(a[h]%2==0 && h>=0)
		{
			h--;
		}
		iter_swap(a.begin()+l,a.begin()+h);
	}
}
	struct s
	{  int a,b;
	  s(int a,int b)
	  {
		  this->a=a;
		  this->b=b;
	  }
	};
 bool comp(s s1,s s2)
 {
		return s1.a<s2.a;
 }		
 int main()
 { vector<s> a;
   s s1(7,9);
   s s2(6,10);
   s s3(4,5);
   s s4(1,3);
   s s5(2,4);
   a.push_back(s1);
   a.push_back(s2);
   a.push_back(s3);
   a.push_back(s4);
   a.push_back(s5);
   sort(a.begin(),a.end(),comp);
   int c=0;
   for(int i=1;i<a.size();i++)
   {  if(a[i-1].a<a[i].b)
	   continue;
      else
		  c++;
   }
   cout<<c;
   return 0;
 }
	