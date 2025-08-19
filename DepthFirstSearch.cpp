#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<int>>&adj,vector<int>&visited,vector<int>&ans)
{
    visited[node]=1;
    ans.push_back(node);
    for(auto it:adj[node])
    {
        if(!visited[it])
        {
            dfs(it,adj,visited,ans);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>visited(n,0);
    vector<int>ans;

    int s;
    cin>>s;

    dfs(s,adj,visited,ans);


    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
