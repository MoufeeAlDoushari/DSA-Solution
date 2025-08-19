#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    // Step 1: Bellman-Ford from a new source (node n)
    vector<int> h(n+1, INF);
    h[n] = 0;

    // Extend graph with edges from new node n to all nodes
    vector<vector<pair<int,int>>> adj_ext = adj;
    adj_ext.resize(n+1);
    for (int i = 0; i < n; i++) {
        adj_ext[n].push_back({i, 0});
    }

    // Relax edges n times
    for (int k = 0; k < n; k++) {
        for (int u = 0; u <= n; u++) {
            if (h[u] == INF) continue;
            for (auto e : adj_ext[u]) {
                int v = e.first, w = e.second;
                if (h[v] > h[u] + w) {
                    h[v] = h[u] + w;
                }
            }
        }
    }

    // Step 2: Reweight edges
    vector<vector<pair<int,int>>> newAdj(n);
    for (int u = 0; u < n; u++) {
        for (auto e : adj[u]) {
            int v = e.first, w = e.second;
            int new_w = w + h[u] - h[v];
            newAdj[u].push_back({v, new_w});
        }
    }

    // Step 3: Dijkstra from each node
    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int src = 0; src < n; src++) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[src][src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [du, u] = pq.top();
            pq.pop();
            if (du != dist[src][u]) continue;

            for (auto e : newAdj[u]) {
                int v = e.first, w = e.second;
                if (dist[src][v] > dist[src][u] + w) {
                    dist[src][v] = dist[src][u] + w;
                    pq.push({dist[src][v], v});
                }
            }
        }
    }

    // Step 4: Fix distances using potentials
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (dist[u][v] < INF) {
                dist[u][v] += h[v] - h[u];
            }
        }
    }

    // Print matrix
    cout << "All-Pairs Shortest Path Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] >= INF/2) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
