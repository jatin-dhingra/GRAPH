#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n{},m{};
  cin>>n>>m;

  vector<pair<int,int>>adj[n+1];
  for(int i{};i<n;i++){
    int u{},v{},wt{};
    cin>>u>>v>>wt;
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
  }
  vector<int>parent(n,-1),mst(n,0),key(n,INT_MAX);

  key[0]=0;
  parent[0]=-1;

  for(int count{};count<n-1;count++)
  {
      int minn=INT_MAX,u{};

      for(int v{};v<n;v++)
      {
        if(mst[v]==0 && key[v]<minn)
        {
          minn=key[v];
          u=v;
        }
      }
      mst[u]=1;

      for(auto it:adj)
      {
        int v=it.first;
        int w=it.second;
        if(mst[v]==0 && w<key[v])
        {
          parent[v]=u;
          key[v]=w;
        }
      }
  }
  for(int i{};i<n;i++)
  {
    cout<<parent[i]<<" "<<i<<endl;
  }

}
