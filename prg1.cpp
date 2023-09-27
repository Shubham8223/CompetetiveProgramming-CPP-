#include<bits/stdc++.h>
using namespace std;
int longestsum(vector<int> arr,int sum)
{   int res=INT_MIN,pre_sum=0;
	unordered_map<int,int> m;
	for(int i=0;i<arr.size();i++)
	{    pre_sum+=arr[i];
		if(pre_sum==sum)
			res= max(i+1,res);
		else if(m.find(pre_sum-sum)!=m.end())
			res=max(i-m[pre_sum-sum],res);
		else
		{
			m[pre_sum]=i;
		}
	}
	return res;
}

void snake(vector<vector<int>> arr)
{   
	for(int i=0;i<arr.size();i++)
	{ 
		if(i%2==0)
		{
			for(int k=0;k<arr[0].size();k++)
			{
				cout<<arr[i][k];
			}
		}
		else
		{	
			for(int k=arr[0].size()-1;k>=0;k--)
			{
				cout<<arr[i][k];
			}
		}
	}
}
void spiral(vector<vector<int>> arr)
{
	int r=arr.size();
	int c=arr[0].size();
	int r1=0,c1=0;
	while(c>=0&&r>=0&&r1<arr.size()&&c1<arr[0].size())
	{	for(int i=r1;i<c;i++)
		{
			cout<<arr[r1][i];
		}
		for(int i=r1+1;i<r;i++)
		{ cout<<arr[i][c-1];
		}
		for(int i=c-2;i>=c1;i--)
		{
			cout<<arr[r-1][i];
		}
		for(int i=r-2;i>r1;i--)
		{
			cout<<arr[i][c1];
		}
		r--;c--;
		r1++;c1++;
	}
}
void revsen(string s)
{
		stack<char> st;
		for(int i=s.length()-1;i>=0;i--)
		{
			if(s[i]==' ')
			{
				while(st.empty()==false)
				{
					cout<<st.top();
					st.pop();
				}
				cout<<" ";
			}
			else
			{
				st.push(s[i]);
			}
		}
		while(st.empty()==false)
				{
					cout<<st.top();
					st.pop();
				}
}
		 
int dist(string str)
{       unordered_set<char> s;	
		s.insert(str[0]);
		int k=0,res=1,max1=INT_MIN;
		for(int i=1;i<str.length();i++)
		{   if(s.find(str[i])!=s.end())
			{   s.insert(str[i]);
		        res++;
				max1=max(res,max1);
			}
			else
			{
				
			

	
int s1(int x)
{ return x==0?-1:1;
}	
int main()
{
   string s="I love coding";
   revsen(s);
	return 0;
}
	
			