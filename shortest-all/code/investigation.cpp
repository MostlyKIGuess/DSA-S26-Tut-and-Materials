#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define rep(i, a, b) for (int i = a; i < b; i++)

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
	int a, b, c;
	cin >> a >> b >> c;
	adj[a].push_back({b, c});
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
		   greater<pair<long long, int>>>
	pq;
    vector<long long> dist(n + 1, INF);
    vector<long long> cnt(n + 1, 0);
    vector<long long> min_e(n + 1, 0);
    vector<long long> max_e(n + 1, 0);
    vector<int> v(n + 1, 0);
    dist[1] = 0;
    cnt[1] = 1;
    pq.push({0, 1});
    while (!pq.empty()) {
	pair<long long, int> top = pq.top();
	int u = top.second;
	pq.pop();
	if (v[u])
	    continue;
	v[u] = 1;
	for (auto e : adj[u]) {
	    int w = e.second;
	    int next = e.first;
	    int new_dist = dist[u] + w;
	    if (new_dist == dist[next]) {
		cnt[next] = (cnt[next] + cnt[u]) % MOD;
		min_e[next] = min(min_e[next], min_e[u] + 1);
		max_e[next] = max(max_e[next], max_e[u] + 1);
	    } else if (new_dist < dist[next]) {
		dist[next] = new_dist;
		cnt[next] = cnt[u];
		min_e[next] = min_e[u] + 1;
		max_e[next] = max_e[u] + 1;
		pq.push({new_dist, next});
	    }
	}
    }
    cout << dist[n] << " " << cnt[n] << " " << min_e[n] << " " << max_e[n];
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
