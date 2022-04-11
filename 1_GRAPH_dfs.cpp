#include <bits/stdc++.h>
using namespace std;
#define pb push_back

void dfstraversal(int &x,vector<int>&visited,vector<int>adj[],vector<int>&dfsvec)
{
  dfsvec.push_back(x);
  visited[x]=1;
  for(auto i:adj[x])
  {
    dfstraversal(x,visited,adj,dfsvec);
  }
}

void dfs(vector<int>adj[],int n)
{
  vector<int>dfsvec;
  vector<int>visited(n+1,0);
  for(int i{1};i<=n;i++){
    if(!visited[i])
    {
      dfstraversal(i,visited,adj,dfsvec);
    }
  }
  for(int i{};i<dfsvec.size();i++){
    cout<<dfsvec[i]<<" ";
  }
}

int main()
{
  int n{},m{};
  cin>>n>>m;

  vector<int>adj[n+1];
  for(int i{};i<m;i++)
  {
    int u{},v{};
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs(adj,n);

}
