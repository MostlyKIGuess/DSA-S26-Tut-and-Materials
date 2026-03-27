#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> a(n);

    for(int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        a[x].push_back({w, y});
    }

    vector<vector<long long>> dist(n, vector<long long>(2, INF));
    dist[0][0] = 0;

    priority_queue<pair<long long,pair<int,int>>, vector<pair<long long,pair<int,int>>>, greater<pair<long long,pair<int,int>>>> pq;
    pq.push({0, {0, 0}});

    while(!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        long long d = curr.first;
        int node = curr.second.first;
        int used = curr.second.second;

        if(d > dist[node][used]) continue;

        for(auto it : a[node]) {
            int next = it.second;
            long long w = it.first;

            if(dist[node][used] + w < dist[next][used]) {
                dist[next][used] = dist[node][used] + w;
                pq.push({dist[next][used], {next, used}});
            }

            if(!used && dist[node][0] + w/2 < dist[next][1]) {
                dist[next][1] = dist[node][0] + w/2;
                pq.push({dist[next][1], {next, 1}});
            }
        }
    }

    cout << dist[n-1][1] << endl;
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
