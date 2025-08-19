#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m;
cin>>n>>m;
vector<vector<pair<int,int>>>adj(n);;
for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].push_back({v,w});
}

int s;
cin>>s;

vector<int>dist(n,1e9);
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

pq.push({0, s});
dist[s]=0;


while(!pq.empty()){
    int dis=pq.top().first;
    int node=pq.top().second;

    pq.pop();

    for(auto it:adj[node]){
         int adjNode = it.first;
         int edgeWeight = it.second;

        if(dis+edgeWeight<dist[adjNode]){
            dist[adjNode]=dis+edgeWeight;
            pq.push({dist[adjNode],adjNode});
        }
    }
}

for(int i=0;i<n;i++){
    cout<<dist[i]<<" ";
}
cout<<endl;

}
