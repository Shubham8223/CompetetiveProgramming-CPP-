#include<bits/stdc++.h>
using namespace std;
int main()
{  string w;
   getline(cin,w);
  int flag=INT_MIN;
    for(int i=w.length()-1;i>0;i--)
{   
    for(int j=i-1;j>=0;j--)
    {
        if(w[i]>w[j])
        {  auto u=max_element(w.begin()+j+1,w.end())-w.begin();
	       cout<<w[j]<<u;
           swap(w[u],w[j]);
            flag=j;
            break;
        }
    }
     if(flag!=INT_MIN)
        break;
}
sort(w.begin()+flag+1,w.end());
cout<<w;
 return 0;
 }
 if(A[i-1][j])
          {
              if(A[i][j]>A[i-1][j])
               {
                   c+=A[i][j]-A[i-1][j];
               }
          }
          if(A[i+1][j])
          {
              if(A[i][j]>A[i+1][j])
               {
                   c+=A[i][j]-A[i+1][j];
               }
          }