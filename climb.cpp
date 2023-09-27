#include<bits/stdc++.h>
using namespace std;
void climbingLeaderboard(vector<int> ranked, vector<int> player) 
{ vector<int> v;
 int i=0,m=INT_MAX;
  map<int,int> s;
   for(auto &it:ranked)
   {  if(m!=it)
       { i++;
           s[it]=i;
       }
       m=it;
   }
   for(auto &k:player)
   { auto j=upper_bound(ranked.rbegin(),ranked.rend(),k);
       if(j!=ranked.rend())
		   v.push_back(s[*j]+1);
	   else
		   v.push_back(1);
	   
   }
}
int main()
{
   vector<int> ranked={100,90,90,30};
   vector<int> player={5,80,105};
   climbingLeaderboard(ranked,player);
   return 0;
  }
   