#include<bits/stdc++.h>
using namespace std;
#define v vector<char>
vector<v> g;
void per(v j,int l,int r)
{   
	if(l==r)
	{  g.push_back(j);
       return ;
	}
	for(int i=l;i<=r;i++)
	{
		swap(j[l],j[i]); 
		per(j,l+1,r);
		swap(j[i],j[l]);
	}
}
int main()
{  int n,i=0;
   cin>>n;
   v st,r;
   while(i<n)
   {
	   char u;
	   cin>>u;
	   st.push_back(u);
	   i++;
   }
   r=st;
   per(r,0,r.size()-1);
   for(auto it:g)
   { for(auto j:it)
	   cout<<j<<" ";
   cout<<endl;
   } return 0;
}
  
	
	
		
	