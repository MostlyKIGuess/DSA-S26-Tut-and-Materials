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
ll dist[2505];
int parent[2505];

void solve() {
    cin >> n >> m;

    rep(i, 0, m) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        edges.pb({u, v, w});
    }

    rep(i, 0, n) {
        dist[i] = 0;
        parent[i] = -1;
    }

    int relax_node = -1;

    rep(iter, 0, n) {
        relax_node = -1;
        rep(i, 0, m) {
            int u = edges[i].from;
            int v = edges[i].to;
            ll w = edges[i].weight;
            if(dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                relax_node = v;
            }
        }
    }

    if(relax_node == -1) {
        cout << "NO" << endl;
    } else {
        int cycle_node = relax_node;
        rep(i, 0, n) {
            cycle_node = parent[cycle_node];
        }

        vector<int> cycle;
        int curr = cycle_node;
        do {
            cycle.pb(curr);
            curr = parent[curr];
        } while(curr != cycle_node);
        cycle.pb(cycle_node);

        reverse(all(cycle));

        cout << "YES" << endl;
        for(int v : cycle) {
            cout << v + 1 << " ";
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
