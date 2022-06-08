#include <bits/stdc++.h>
using namespace std;
int main(){
  int n{},m{};
  cin>>n>>m;
  vector<int>adj[n+1];

  vector<int>dis(n,0);
  queue<int>q;
  for(int i{};i<n;i++)
  {
    int u{},v{};
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int source{};
  cin>>source;
  for(int i{};i<n;i++){
    dis[i]=INT_MAX;
  }
  dis[source]=0;

  q.push(source);
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
  for(auto i:dis)
  {
    cout<<i<<" ";
  }
  cout<<endl;


}
