#include <bits/stdc++.h>
using namespace std;
#define pb push_back

bool checkcycle(int i,int par,vector<int>adj[],vector<int>visited)
{
  visited[i]=true;

  for(auto num:adj[i])
  {
    if(visited[num]==0)
    {
      if(checkcycle(num,i,adj,visited))
      {
        return true;
      }
    }
    else if(num!=par)
    {
      return true;
    }
  }
  return false;

}

int main()
{
  int n{},m{};
  cin>>n>>m;
  vector<int>adj[n+1];
  vector<int>visited(n+1,0);
  for(int i{};i<m;i++){
    int u{},v{};
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  for(int i{};i<n;i++){
    if(!visited[i])
    {
      if(checkcycle(i,-1,adj,visited))
      {
        return true;
      }
    }
  }
}
