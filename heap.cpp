#include<bits/stdc++.h>
using namespace std;
struct heap
{
	int *a;
	int size;
	int cap;
	heap(int c)
	{
		cap=c;
		size=0;
		a=new int[c];
	}
	int left(int i)
	{
		return 2*i+1;
	}
	int right(int i)
	{
		return 2*i+2;
	}
	int parent(int i)
	{
		return floor((i-1)/2);
	}
	void ins(int x)
	{  if(size==cap)
		return;
		a[size]=x;
		size++;
		int paw=size-1;
		while(paw!=0 && a[parent(paw)]>x)
		{
			swap(a[paw],a[parent(paw)]);
			paw=parent(paw);
		}
	}
    void print()
	{
        for(int i=0;i<size;i++)
               cout<<a[i]<<endl;		   
    }
    void heapify(int i)
    {  if(a[i]
	   int m=min({a[i],a[left(i)],a[right(i)]});
	    if(m==a[i])
		   return;
	   
	   
		
	}		
};
int main()
{
	heap h(10);
	h.ins(20);
	h.ins(40);
	h.ins(50);
	h.ins(10);
	h.print();
	return 0;
}