#include <bits/stdc++.h>
using namespace std;

bool cycle(int node,vector<int>adj[],vector<int>&vec)
{
  if(vis[node]==-1)
  {
    vis[node]=1;
  }
  for(auto it:ajd[node])
  {
    if(vis[it]==-1)
    {
      vis[it]=1-vis[node];
      if(!(cycle(it,adj,vis)))
      {
        cout<<"false";
        break;
      }
    }
    else if(vis[it]==vis[node])
    {
      cout<<"false"<<endl;
      break;
    }
  }
  cout<<"true"<<endl;

}

int main()
{
  int n{},m{};
  cin>>n>>m;

  vector<int>adj[n+1];
  vector<int>vis(n+1,-1);
  for(int i{};i<n;i++)
  {
    int u{},v{};
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i{};i<n;i++)
  {
    if(vis[i]=-1)
    {
      if(!(cycle(i,adj,vis)))
      {
        cout<<"false"
      }
    }
  }
  cout<<"True"<<'\n';
}
