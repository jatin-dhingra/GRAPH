#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int>adj[],int n)
{
  vector<int>bfsvector;
  int visited[n+1];
  memset(visited,0,sizeof(visited));

  for(int i{1};i<=n;i++)
  {
    if(!visited[i])
    {
      queue<int>q;
      q.push(i);
      visited[i]=1;
      while(!q.empty())
      {
        int num=q.front();
        q.pop();
        bfsvector.push_back(num);
        for(auto i:adj[num])
        {
          if(!visited[i])
          {
            q.push(i);
            visited[i]=1;
          }
        }
      }
    }
  }

  for(int i{};i<bfsvector.size();i++){
    cout<<bfsvector[i]<<" ";
  }

}

int main()
{
  int n{},m{};
  cin>>n>>m;
  vector<int>adj[n+1];
  for(int i{};i<m;i++){
    int u{},v{};
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  bfs(adj,n);
}
