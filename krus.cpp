#include<bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define ver 5
class disjoint
{	int par[ver];
	int rank[ver];
	public:
	disjoint()
	{ for(int i=0;i<ver;i++)
		{	par[i]=i;
			rank[i]=0;
		}
	}
	int find(int x)
	{
		if(x==par[x])
			return x;
		par[x]=find(par[x]);
		return par[x];
	}
	bool unionele(int x,int y)
	{
		int pax=find(x);
		int pay=find(y);
		if(pax==pay)
			return false;
		if(rank[pax]<rank[pay])
			par[pax]=pay;
		else if(rank[pax]>rank[pay])
			par[pay]=pax;
		else
		{	par[pax]=pay;
			rank[pay]++;
		}
		return true;
	}
};
class edge
{   public:
	int src;
	int dst;
	int w;
	edge()
	{
	}
	edge(int src,int dst,int w)
	{
		this->src=src;
		this->dst=dst;
		this->w=w;
	}
	friend class graph;
};
class graph
{
	int v;
	vector<edge> li;
	public:
	graph(int v)
	{
		this->v=v;
	}
	void add(edge e)
	{ 	
		li.push_back(e);
	}
	void print()
	{
		for(auto it:li)
		{
			cout<<"src :"<<it.src<<" "<<"dst :"<<it.dst<<" "<<"w :"<<it.w;
			cout<<endl;
		}
	}		
	void elesort()
	{	
			sort(li.begin(),li.end(),[=](edge e1,edge e2)->bool{return e1.w<e2.w;});
	}
	int kruskal()
	{   disjoint obj;
		int res=0;
		int cnt=0;
		for(auto it:li)
		{
			if(obj.unionele(it.src,it.dst))
			{
				cnt++;
				res+=it.w;
				cout<<it.src<<" "<<it.dst<<endl;
			}
		}
		cout<<endl;
		return res;
	}
		
};

int main()
{
	graph g(5);
	edge e1(1,3,3);
	edge e2(2,3,4);
	edge e3(1,2,5);
	edge e4(0,2,8);
	edge e5(0,1,10);
	edge e6(2,4,12);
	edge e7(3,4,15);
	g.add(e1);
	g.add(e2);
	g.add(e3);
	g.add(e4);
	g.add(e5);
	g.add(e6);
	g.add(e7);
	g.print();
	g.elesort();
	cout<<endl;
	g.print();
	cout<<endl;
	cout<<"MST :"<<g.kruskal();
	return 0;
}