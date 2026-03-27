#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;

vector<int> adj[MAX_N];
int indeg[MAX_N];
int dp[MAX_N], parent[MAX_N];

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n+2; i++) {
        adj[i].clear();
        indeg[i] = 0;
        dp[i] = -1;
        parent[i] = -1;
    }

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(indeg[i] == 0) q.push(i);
    }

    vector<int> topo;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for(int v : adj[u]) {
            indeg[v]--;
            if(indeg[v] == 0) q.push(v);
        }
    }

    dp[0] = 1;

    for(int u : topo) {
        if(dp[u] == -1) continue;
        for(int v : adj[u]) {
            if(dp[u] + 1 > dp[v]) {
                dp[v] = dp[u] + 1;
                parent[v] = u;
            }
        }
    }

    if(dp[n-1] == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << dp[n-1] << endl;
        vector<int> path;
        for(int v = n-1; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        for(int i = 0; i < path.size(); i++) {
            cout << path[i] + 1;
            if(i < path.size()-1) cout << " ";
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
