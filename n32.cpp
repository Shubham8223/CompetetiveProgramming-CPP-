#include<bits/stdc++.h>
using namespace std;
class minheap
{   public:
	int *a;
	int size;
	int cap;
	minheap(int c)
	{
		a=new int[c];
	    size=0;
		cap=c;
	}
	int left(int k)
	{
		return 2*k+1;
	}
	int right(int k)
	{
		return 2*k+2;
	}
	int parent(int k)
	{
		return floor((k-1)/2);
	}
	void ins(int k)
	{
		size++;
		a[size-1]=k;
		heapif(size-1);
	}
	void heapif(int x)
	{
	    while(x!=0)
		{ int i=parent(x);
		  if(a[i]>a[x])
		  { swap(a[i],a[x]);
	        x=i;
		  }
	      else
		  break;
        }
	}
};
int main()
{
	minheap m(10);
	m.ins(10);
	m.ins(20);
	m.ins(15);
	m.ins(40);
	m.ins(50);
	m.ins(100);
	m.ins(25);
	m.ins(45);
	m.ins(12);
	for(int i=0;i<m.size;i++)
    { cout<<m.a[i]<<endl;
	}
 return 0;
}
    
 