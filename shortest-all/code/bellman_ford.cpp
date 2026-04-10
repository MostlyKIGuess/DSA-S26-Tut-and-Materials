// Bellman-Ford Algorithm
// Handles negative edges and detects negative cycles

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)

const ll INF = 1e18;

struct Edge {
    int from, to;
    ll weight;
};

int n, m;
vector<Edge> edges;
ll dist[100005];

bool bellman_ford(int source) {
    rep(i, 0, n) dist[i] = INF;
    dist[source] = 0;

    rep(iter, 0, n-1) {
        bool updated = false;
        rep(i, 0, m) {
            int u = edges[i].from;
            int v = edges[i].to;
            ll w = edges[i].weight;
            if(dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                updated = true;
            }
        }
        if(!updated) break;
    }

    bool has_neg_cycle = false;
    rep(i, 0, m) {
        int u = edges[i].from;
        int v = edges[i].to;
        ll w = edges[i].weight;
        if(dist[u] != INF && dist[u] + w < dist[v]) {
            has_neg_cycle = true;
            break;
        }
    }

    return has_neg_cycle;
}

void solve() {
    cin >> n >> m;
    edges.clear();

    rep(i, 0, m) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        edges.pb({u, v, w});
    }

    bool has_neg = bellman_ford(0);

    if(has_neg) {
        cout << "Negative cycle detected!" << endl;
    } else {
        rep(i, 0, n) {
            if(dist[i] == INF) cout << "INF ";
            else cout << dist[i] << " ";
        }
        cout << endl;
    }
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
