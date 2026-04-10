#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll INF = 1e18;
int n, m;
ll dist[505][505];

void floyd_warshall() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void solve() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dist[i][j] = (i == j) ? 0 : INF;

    for(int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    floyd_warshall();

    int q; cin >> q;
    while(q--) {
        int u, v; cin >> u >> v;
        if(dist[u][v] >= INF) cout << -1 << "\n";
        else cout << dist[u][v] << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
