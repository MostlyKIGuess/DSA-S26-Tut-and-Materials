#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

void dijkstra(int src, vector<vector<pair<int,int>>>& adj, vector<long long>& dist) {
    int n = adj.size();
    vector<int> vis(n, 0);

    for(int i = 0; i < n; i++) dist[i] = INF;
    dist[src] = 0;

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    pq.push({0, src});

    while(!pq.empty()) {
        pair<long long,int> temp = pq.top();
        pq.pop();
        int node = temp.second;

        if(vis[node]) continue;
        vis[node] = 1;

        for(auto it : adj[node]) {
            int next = it.second;
            long long w = it.first;
            if(dist[node] + w < dist[next]) {
                dist[next] = dist[node] + w;
                pq.push({dist[next], next});
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({w, v});
    }

    vector<long long> dist(n);
    dijkstra(0, adj, dist);

    for(int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
