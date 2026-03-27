#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;

vector<int> adj[MAX_N];
int indeg[MAX_N];

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n+2; i++) {
        adj[i].clear();
        indeg[i] = 0;
    }

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indeg[i] == 0) q.push(i);
    }

    vector<int> result;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for(int v : adj[u]) {
            indeg[v]--;
            if(indeg[v] == 0) q.push(v);
        }
    }

    if(result.size() != n) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for(int x : result) cout << x << " ";
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
