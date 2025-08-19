#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m;
cin>>n>>m;
vector<vector<pair<int,int>>>adj(n);
for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].push_back({v,w});
}
vector<int>dist(n,1e9);
vector<int>parent(n,-1);

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<int>path;
int s;
cin>>s;
pq.push({0,s});
dist[s]=0;
int des;
cin>>des;
while(!pq.empty()){
    int wt=pq.top().first;
    int node=pq.top().second;
    pq.pop();

    for(auto it:adj[node]){
        int adjNode=it.first;
        int edgeweight=it.second;

        if(edgeweight+wt<dist[adjNode]){
            dist[adjNode]=edgeweight+wt;
            pq.push({dist[adjNode],adjNode});
            parent[adjNode]=node;
        }
    }
}
    int node=des;
    while(node!=-1) {
        path.push_back(node);
        node = parent[node];
    }

    reverse(path.begin(),path.end());

    for (int i=0;i<path.size();i++) {
        cout<<path[i]<<" ";
    }
    cout << endl;


    cout<<"Distance: "<<dist[des]<<endl;
}
