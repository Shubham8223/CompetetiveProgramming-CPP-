#include<bits/stdc++.h>
using namespace std;
vector<int> p(101);
bool comp(int k1,int k2)
{
    return p[k2]<p[k1];
}
int main()
{   vector<int> k,a={1,2,2,3,1,2};
   set<int> b;
    int re=0;
  for(auto it:a)
    {   p[it]++;
        b.insert(it);
    }
sort(k.begin(),k.end(),comp);
for(auto it:b)
{   k.push_back(it);
}
  for(auto it:k)
	  cout<<it<<endl;
 for(int i=0;i<k.size()-1;i++)
{
    if(abs(k[i]-k[i+1])==1)
	{ re=p[k[i]]+p[k[i+1]];
      break;
	}
}
cout<<re;
  return 0;
}