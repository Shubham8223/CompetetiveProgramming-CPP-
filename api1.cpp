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
		
		
 int main()
 { vector<int> a={1,2,3,5,2,4,8,0,12,4,66,23};
	seg(a);
   for(auto it:a)
   {
	   cout<<it<<endl;
   }
   return 0;
 }
	
	