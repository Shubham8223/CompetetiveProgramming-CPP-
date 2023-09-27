#include<bits/stdc++.h>
using namespace std;
#define vec vector<int>
struct graph
{	vec *a;
    int v;
	graph(int vertex)
	{
	     v=vertex;
		 a=new vec[v];
	}
	void print()
	{
		for(int i=0;i<v;i++)
		{
			for(auto x:a[i])
			cout<<x<<" ";
			cout<<endl;
		}
	}
	void add(int v,int u)
	{
	      a[v].push_back(u);
    }
	void rem(int v,int u)
	{
	    remove(a[v].begin(),a[v].end(),u);
	}
	void bfsrec(int s,vector<bool> &b,int &c)
	{      queue<int> q;
	       q.push(s);
		   b[s]=true;
		   c++;
		   while(q.empty()==false)
		   {   int u=q.front();
	           q.pop();
			   cout<<u<<" ";
			   for(auto x:a[u])
			   { if(b[x]==false)
				   {
					   q.push(x);
					   b[x]=true;
				   }
			   }
		   }
		   cout<<endl;
	}
		
	void bfs()
	{
		vector<bool> b(v);
		for(int i=0;i<v;i++)
		{
			b[i]=false;
	    }
		int c=0;
		for(int i=0;i<v;i++)
		{
			if(b[i]==false)
				bfsrec(i,b,c);
		}
		cout<<"no of components:"<<c;
	}
	void dfsrec(vector<bool> &b,int s)
	{
		b[s]=true;
		cout<<s<<" ";
		for(auto x:a[s])
		{
			if(b[x]==false)
			{   
		        dfsrec(b,x);
			}
		}
	}
	void dfs()
	{
		vector<bool> b(v);
		for(int i=0;i<v;i++)
		{
			b[i]=false;
	    }
		for(int i=0;i<v;i++)
		{
			if(b[i]==false)
				dfsrec(b,i);
		}
	}
	bool cyclerecdir(vector<bool> &b,vector<bool> &r,int s)
	{	b[s]=true;
	    r[s]=true;
		for(auto x:a[s])
		{
			if(b[x]==false && cyclerecdir(b,r,x))
				return true;
			else if(r[x]==true)
			{
				return true;
			}
		}
		r[s]=false;
		return false;
	}
	bool cycledir()
	{
		vector<bool> b(v),r(v);
		for(int i=0;i<v;i++)
		{
			b[i]=false;
			r[i]=false;
	    }
		for(int i=0;i<v;i++)
		{
			if(b[i]==false)
				if(cyclerecdir(b,r,i)==true)
					return true;
		}
		return false;
	}
	bool cyclerec(vector<bool> &b,int s,int p)
	{
		b[s]=true;
		for(auto x:a[s])
		{
			if(b[x]==false && cyclerec(b,x,s))
			{
				return true;
			}
			else if(p!=x)
			{ 
			return true;
			}
		}
		return false;
	}
	bool cycle()
	{
		vector<bool> b(v);
		for(int i=0;i<v;i++)
		{
			b[i]=false;
	    }
		for(int i=0;i<v;i++)
		{
			if(b[i]==false)
				if(cyclerec(b,i,-7))
					return true;
		}
		return false;
	}
	void topo()
	{
		vec ind(v,0);
		int c=0;
		for(int i=0;i<v;i++)
		{
			for(auto x:a[i])
			{
				ind[x]++;
			}
		}
		queue<int> q;
		for(int i=0;i<v;i++)
		{
			if(ind[i]==0)
				q.push(i);
		}
		while(q.empty()==false)
		{  int u=q.front();
	       cout<<u<<" ";
	       q.pop();
		   c++;
		   for(auto x:a[u])
		   {  ind[x]--;
              if(ind[x]==0)
			  q.push(x);
           }
        }
		string s=(c==v)?"acyclic":"cyclic";
        cout<<endl<<s;		
	}
				
};



int main()
{  graph g(6);
   g.add(0,2);
   g.add(0,3);
   g.add(1,3);
   g.add(1,4);
   g.add(3,5);
   g.add(5,0);
   g.print();
   g.topo();
   return 0;
  }
 
	
    