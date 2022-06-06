#include <bits/stdc++.h>
using namespace std;
void cycle(int node,vector<int>adj[],vector<int>&vis,stack<int>st)
{
  vis[node]=1;
  for(auto it:adj[node])
  {
    if(!vis[it])
    {
      cycle(it,adj,vis,st);
    }
  }
  st.push(node);
}

int main()
{
  int n{},m{};
  cin>>n>>m;
  stack<int>st;
  vector<int>adj[n+1];
  vector<int>vis(n+1,0);
  for(int i{};i<n;i++){
    int u{},v{};
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i{};i<n;i++)
  {
    if(!vis[i])
    {
      cycle(i,adj,vis,st);
    }
  }
  vector<int>ans;
  while(!st.empty()){
    ans.push_back(st.top());
    st.pop();
  }
  for(auto it:ans){
    cout<<it<<" ";
  }
}
