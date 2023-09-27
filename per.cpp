#include<bits/stdc++.h>
using namespace std;
vector<string> g;
void subgen(string t,int i,string r)
{ if(i==t.size())
	{   if(r.size()>1)
		g.push_back(r);
		return;
	}
	subgen(t,i+1,r);
	r.push_back(t[i]);
	subgen(t,i+1,r);
	r.pop_back();
}
int main()
{  string s,r;
   cin>>s;
   subgen(s,0,r);
   for(auto it:g)
   { cout<<it<<endl;
   } return 0;
}
  
	