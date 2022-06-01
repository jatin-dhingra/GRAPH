#include <bits/stdc++.h>
using namespace std;

bool cycledfs(int node, int parent,vector<int>&vec,vector<int>&vec[])
{
  vis[node]=1;
  for(auto it:vec[node])
  {
    if(!vis[it])
    {
      if(cycledfs(it,node,vec,vis))
      {
        return true;
      }
      else if(it!=parent){
        return true;
      }
    }
  }
  return false;
}

int main()
{
  int n{},m{};
  cin>>n>>m;
  vector<int>vis(n+1,0);
  vector<int>vec[m+1];
  for(int i{};i<m;i++){
    int u{},v{};
    cin>>u>>v;
    vec[u].push_back(v);
    vec[v].push_back(u);
  }

  for(int i{};i<m;i++){
    if(vis[i]==0)
    {
      if(cycledfs(i,-1,vec,vis))
      {
        cout<<"Cycle";
      }
    }
  }

}
