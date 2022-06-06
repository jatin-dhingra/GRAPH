#include <bits/stdc++.h>
using namespace std;

bool cycle(int node,vector<int>&adj[],vector<int>&vis,vector<int>&dfsvis)
{
  vis[node]=1; 
  dfsvis[node]=1;
  for(auto it:adj[node])
  {
    if(!vis[it])
    {
      if(cycle(it,adj,vis,dfsvis))
      {
        return true;
      }
    }
    else if(dfsvis[it])
    {
      return true;
    }
  }
  dfsvis[node]=0;
  return false;
}

int main()
{
  int n{},m{};
  cin>>n>>m;
  vector<int>adj[n+1];
  vector<int>vis(n+1,0);
  vector<int>dfsvis(n+1,0);

  for(int i{};i<n;i++)
  {
    int u{},v{};
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i{};i<n;i++)
  {
    if(!vis[i])
    {
      if(cycle(i,adj,vis,dfsvis))
      {
        cout<<"YES cycle is there"<<endl;
      }
    }
  }
  cout<<"NO cycle is there"<<endl;
}
