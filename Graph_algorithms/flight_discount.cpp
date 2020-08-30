#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mxN = 1e5;

int n, m;
vector<pair<int, int>> adj[mxN], adj2[mxN];
ll dst[mxN], dst2[mxN];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

void djk(vector<pair<int, int>> ad[], ll d[], int st) {
	d[st] = 0;
	pq.push({0, st});
	while(!pq.empty()) {
		int u = pq.top().second;
		ll val = pq.top().first;
		pq.pop();
		if(val > d[u]) continue;
		for(auto v: ad[u]) {
			if(d[u] + v.second < d[v.first]) {
				d[v.first] = d[u] + v.second;
				pq.push({d[v.first], v.first});
			}
		}
	}
}


int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c, --a, --b;
		adj[a].push_back({b, c});
		adj2[b].push_back({a, c});
	}
	memset(dst, 0x3f, sizeof(dst));
	memset(dst2, 0x3f, sizeof(dst2));
	djk(adj, dst, 0);
	djk(adj2, dst2, n - 1);
	ll ans = 1e15;
	for(int u = 0; u < n; ++u) {
		for(auto v: adj[u]) {
			ans = min(ans, dst[u] + dst2[v.first] + v.second / 2);
		}
	}
	cout << ans << "\n";
}
