#include <bits/stdc++.h>
using namespace std;

void topo(vector<pair<int,int>>adj[],vector<int>&vec,stack<int>&st,int node)
{
  vis[node]=1;
  for(auto it:adj[node])
  {
    if(!vis[it]){
      topo(adj,vis,st,node);
    }
  }
  st.push(node);
}

void shortpath(vector<pair<int,int>>adj[],int n,int source)
{
  vector<int>vis(n,0);
  stack<int>st;
  for(int i{};i<n;i++){
    if(!vis[i])
    {
      topo(adj,vis,st,i);
    }
  }

  vector<int>dis(n,INT_MAX);
  dis[source]=0;
  while(!st.empty()){
    int node=st.top();
    st.pop();
    if(dis[node]!=INT_MAX)
    {
      for(auto it:adj[node])
      {
        if(dis[node]+it.second<dis[it.first])
        {
          dis[it.first]=it.second+dis[node];
        }
      }
    }
    for(int i{};i<n;i++)
    {
      cout<<(dis[i]==INT_MAX)?"Not possible":dis[i]<<" ";
    }
  }
  
   
  
}

int main()
{
  int n{},m{};
  cin>>n>>m;
  // get the topo sort 
  vector<pair<int,int>>adj[n];
  for(int i{};i<m;i++){
    int u{},v{},wt{};
    adj[u].push_back({v,wt}); 
  }

  shortpath(adj,n,0);
  
  
}
