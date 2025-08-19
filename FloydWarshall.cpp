#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m;
cin>>n>>m;
const int INF = 1e9;
vector<vector<int>>v(n,vector<int>(n,INF));
for(int i=0;i<n;i++){
    v[i][i]=0;
}
for(int i=0;i<m;i++){
    int x,y,w;
    cin>>x>>y>>w;
    v[x][y]=w;
}

for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                if(v[i][k]<INF && v[k][j]<INF){
                     v[i][j]=min( v[i][j],v[i][k]+v[k][j]);
                }

        }
    }
}


for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(v[i][j]==INF){
            v[i][j]=-1;
        }
    }
}


for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<v[i][j]<<" ";
    }
    cout<<endl;
}


}
