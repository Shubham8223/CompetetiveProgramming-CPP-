#include<bits/stdc++.h>
using namespace std;
bool check(char c1,char c2)
{
	if(c1=='{'&&c2=='}')
		return true;
	if(c1=='('&&c2==')')
		return true;
	if(c1=='['&&c2==']')
		return true;
	return false;
}
bool balpar(string s)
{	stack<char> st;
    for(int i=0;i<s.length();i++)
	{	if(s[i]=='{'||s[i]=='['||s[i]=='(')
			st.push(s[i]);
		else
		{	if(st.empty())
				return false;
			else if(check(st.top(),s[i]))
				st.pop();
			else
				return false;
		}
	}
	return st.empty();
}
void stock(int arr[],int arr1[],int n)
{
	stack<int> st;
	st.push(arr[0]);
	fill(arr1,arr1+n,1);
	for(int i=1;i<n;i++)
	{
	   while(st.empty()==false&&st.top()<=arr[i])
			{	arr1[i]++;
				st.pop();
		    }
			arr1[i]=st.empty()?i+1:arr1[i];
			st.push(arr[i]);
	}
}
void gts(int arr[],int n)
{
	stack<int> st;
	st.push(arr[0]);
	cout<<-1<<" ";
	for(int i=1;i<n;i++)
	{
	   while(st.empty()==false&&st.top()<arr[i])
			{	
		      st.pop();
		    }
			int p=st.empty()==true?-1:st.top();
			cout<<p<<" ";
			st.push(arr[i]);
	}
}
void gtes(int arr[],int n)
{
	stack<int> st;
	st.push(arr[n-1]);
	cout<<-1<<" ";
	for(int i=n-1;i>=0;i--)
	{
	   while(st.empty()==false&&st.top()<arr[i])
			{	
		      st.pop();
		    }
			int p=st.empty()==true?-1:st.top();
			cout<<p<<" ";
			st.push(arr[i]);
	}
}
int main()
{
	int arr[]={15,65,10,18,12,4,6,2,8};
	gts(arr,8);
	return 0;
}