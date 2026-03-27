#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> a(n);
    vector<long long> dist(n, INF);
    vector<int> vis(n, 0);

    for(int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        a[x].push_back({w, y});
    }

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    pq.push({0, 0});
    dist[0] = 0;

    while(!pq.empty()) {
        pair<long long,int> temp = pq.top();
        pq.pop();
        int node = temp.second;
        if(vis[node] == 1) continue;
        vis[node] = 1;

        for(auto it : a[node]) {
            if(dist[it.second] > dist[node] + it.first) {
                dist[it.second] = dist[node] + it.first;
                pq.push({dist[it.second], it.second});
            }
        }
    }

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
