#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;

vector<int> adj[MAX_N], radj[MAX_N];
bool visited[MAX_N];
vector<int> order;

int n, m;

void dfs1(int u) {
    visited[u] = true;
    for(int v : adj[u]) {
        if(!visited[v]) dfs1(v);
    }
    order.push_back(u);
}

void dfs2(int u, vector<int>& comp) {
    visited[u] = true;
    comp.push_back(u);
    for(int v : radj[u]) {
        if(!visited[v]) dfs2(v, comp);
    }
}

void solve() {
    cin >> n >> m;

    for(int i = 0; i < n+2; i++) {
        adj[i].clear();
        radj[i].clear();
        visited[i] = false;
    }
    order.clear();

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) dfs1(i);
    }

    for(int i = 0; i < n+2; i++) visited[i] = false;

    int scc_count = 0;

    for(int i = n-1; i >= 0; i--) {
        if(!visited[order[i]]) {
            vector<int> comp;
            dfs2(order[i], comp);
            scc_count++;
        }
    }

    cout << scc_count << endl;
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
