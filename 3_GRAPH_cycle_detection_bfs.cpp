#include <bits/stdc++.h>
using namespace std;

bool checkcycle(int i,int n,vector<int>arr[],vector<int>visited)
{
    queue<pair<int,int>>q;
    visited[i]=1;
    q.push({i,-1});

    while(!q.empty())
    {
      int node=q.front().first;
      int ind=q.front().second;
      q.pop();
      for(auto x:adj[node])
      {
        if(!visited[x]){
          visited[x]=1;
          q.push({x,node});
        }
        else if(x!=ind)
        {
          return true;
          //cycle in graph
        }
      }
    }
    return false;
    // no cycle in graph 
}

int main()
{
  int n{},m{}:
  cin>>n>>m;
  vector<int>visited(n+1,0);
  vector<int>adj[n+1];
  for(int i{};i<m;i++)
  {
    int u{},v{};
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i{};i<n;i++){
    if(!visited[i])
    {
      checkcycle(i,n,adj,visited);
    }
  }
}
