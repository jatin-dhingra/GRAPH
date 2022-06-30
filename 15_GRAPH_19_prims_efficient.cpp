#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
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

  priority_queue<pp,vector<pp>,greater<pp>>pq;
  parent[0]=-1;
  key[0]=0;
  pq.push({0,0});
  for(int count{};count<n-1;count++)
  {
    int u=pq.top().second;
    pq.pop();
    mst[u]=1;

    for(auto it:adj[u])
    {
      int v=it.first;
      int wt=it.second;
      if(mst[v]==0 && wt<key[v])
      {
        parent[v]=u;
        pq.push({key[v],v});
        key[v]=wt;
      }
    }
  }

}
