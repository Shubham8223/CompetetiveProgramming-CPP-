#include<bits/stdc++.h>
using namespace std;
vector<string> subvec;
void gen(string subset,string target,int i)
{
	if(i==target.size())
	{
		subvec.push_back(subset);
		return;
    }
	gen(subset,target,i+1);
	subset.push_back(target[i]);
	gen(subset,target,i+1);
	subset.pop_back();
}
template<class T>
void swa(T &a,int i,int j)
{  auto temp=a[i];
    a[i]=a[j];
	a[j]=temp;
}
	
void perm(string h,int i)
{
	if(i==h.size())
	{
		cout<<h<<endl;
		return;
	}
	for(int l=i;l<h.size();l++)
	{ swa(h,i,l);
      perm(h,i+1);
	  swa(h,i,l);
	}
}
int main()
{
	perm("ABC",0);
	return 0;
}