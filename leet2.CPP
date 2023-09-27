#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char wc(string g,char r)
{   char j;
	for(int i=g.size()-1;i>=0;i--)
	{
		if(g[i]>r)
		{  
			j=g[i];
			break;
		}
	}
	return j;
}
int main()
{ string w="hefg";
string g1=w.substr(w.size()-1,1);
   int flag=1;
     for(int i=2;i<=w.size();i++)
    {  string g=w.substr(w.size()-i,i);
       cout<<g<<endl;
       string f=g;
       sort(g.begin(),g.end(),greater<char>());
	   cout<<g<<endl;;
       if(f!=g)
       {
           char r=w[0];
		   char y=wc(g1,r);
		   auto it=find(w.begin(),w.end(),y);
		   w[0]=y;
		   cout<<r<<" "<<y<<endl;
		   cout<<it-w.begin()<<endl;
           w[it-w.begin()]=r;
		   cout<<w<<endl;
		   sort(w.begin()+w.size()-i+1,w.end());
		   cout<<w;
           break;
           flag=0;
       }
	   g1=g;
    
    }
    return 0;
}
