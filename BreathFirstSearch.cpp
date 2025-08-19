#include<bits/stdc++.h>
using namespace std;
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

    queue<int>q;
    vector<int>visited(n,0);
    vector<int>bfs;
    int s;
    cin>>s;
    q.push(s);
    visited[s]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                visited[it]=1;
                q.push(it);
            }
        }
    }
    for(int i=0; i<bfs.size(); i++)
    {
        cout<<bfs[i]<<" ";
    }
    cout<<endl;

}
