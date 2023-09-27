#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> a;
	for(int i=0;i<6;i++)
	{
	    int u;
		cin>>u;
		a.push_back(u);
	}
	cout<<*max_element(a.begin(),a.end());
    return 0;
}