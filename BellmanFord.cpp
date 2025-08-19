#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m;
cin>>n>>m;
vector<vector<int>>edges;
for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    edges.push_back({u,v,w});
}
vector<int>dist(n,1e8);
int s;
cin>>s;
dist[s]=0;

for(int i=0;i<n-1;i++){
    for(int j=0;j<m;j++){
    int u=edges[j][0];
    int v=edges[j][1];
    int wt=edges[j][2];

     if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
        dist[v]=dist[u]+wt;
     }

    }
}


for(int i=0;i<n;i++){
    if(dist[i]==1e8){
        cout<<"INF";
    }
    else cout<<dist[i]<<" ";
}
cout<<endl;
}
