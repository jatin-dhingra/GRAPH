#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n{},m{};
  cin>>n>>m;
  vector<int>adj[n+1];
  vector<int>indegree(n ,0);
  vector<int>vis(n+1,0);
  queue<int>q;
  for(int i{};i<n;i++)
  {
    int u{},v{};
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i{};i<n;i++)
  {
    for(auto it:ajd[i])
    {
      indegree[it]++;
    }
  }
  // pushing all node having zero indegree
  for(int i{};i<n;i++){
    if(indegree[i]==0){
      q.push(i);
    }
  }
  vector<int>topo;
  while(!q.empty())
  {
    int node=q.front();
    q.pop();
    topo.push_back(node);
    for(auto it:adj[node])
    {
      indegree[it]--;
      if(indegree[it]==0)
      {
        q.push(it);
      }
    }
  }
  for(auto i:topo)
  {
    cout<<i<<" ";
  }
  cout<<endl;

}
