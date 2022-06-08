#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n{},m{};
  cin>>n>>m;


  vector<int>adj[n+1];
  vector<int>indegree(n ,0);
  vector<int>vis(n+1,0);
  queue<int>q;
  vector<int>topo

  for(int i{};i<n;i++)
  {
    int u{},v{};
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i{};i<n;i++){
    for(auto it:adj[i])
    {
      indegree[it]++;
    }
  }


  for(int i{};i<n;i++)
  {
    if(indegree[i]==0){
      q.push(i);
    }
  }
  int count{};
  while(!q.empty()){
    int node=q.front();
    topo.push_back(node);
    q.pop();
    count++;
    for(auto it:adj[node])
    {
      indegree[it]--;
      if(indegree[it]==0)
      {
        q.push(it);
      }
    }
  }

  // detection of cycle in directed grpah

  if(count==n){
    cout<<"NO cycle"<<endl;
  }
  else
      cout<<"There is a cycle"<<endl;

}
