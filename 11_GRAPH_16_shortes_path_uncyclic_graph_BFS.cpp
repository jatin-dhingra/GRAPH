#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n{},m{};
  cin>>n>>m;
  vector<int>adj[n+1];
  for(int i{};i<m;i++)
  {
    int u{},v{};
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int source{};
  cin>>source;
  queue<int>q;
  q.push(source);
  vector<int>dis(n,INT_MAX);
  dis[source]=0;
  while(!q.empty())
  {
    int node=q.front();
    q.pop();
    for(auto it:adj[node])
    {
      if(dis[node]+1<dis[it])
      {
        dis[it]=dis[node]+1;
        q.push(it);
      }
    }
  }
  for(auto it:dis){
    cout<<it<<" ";
  }
  cout<<endl;

}
