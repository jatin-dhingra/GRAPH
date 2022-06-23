#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n{},m{};
  cin>>n>>m;
  vector<pair<int,int>>adj[n+1];

  for(int i{};i<m;i++)
  {
    int a{},b{},wt{};
    cin>>a>>b>>wt;
    adj[a].push_back({b,wt});
    adj[b].push_back({a,wt});
  }
  int source{};
  cin>>source;

  // use of minheap!
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

  vector<int>dis(n+1,INT_MAX);

  dis[source]=0;
  pq.push({0,source});
  while(!pq.empty())
  {
    int node=pq.top().second;
    int dis=pq.top().first;
    pq.pop();
    for(auto it:adj[node])
    {
      int nextdistance=it.second;
      int nextnode=it.first;
      if(dis[nextnode]>dis+nextdistance)
      {
        dis[nextnode]=dis+nextdistance;
        pq.push({dis[nextnode],nextnode});
      }
    }
  }
  for(int i{};i<n;i++)
  {
    cout<<"dis "<<dis[i]<<" ";
  }

}
