#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
vector<vector<pair<int, int>>> adj;
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
vector<ll> dst;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	adj = vector<vector<pair<int, int>>> (n);
	dst = vector<ll> (n, (1LL << 62));
	for(int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c, --a, --b;
		adj[a].push_back({b, c});
	}
	dst[0] = 0;
	pq.push({dst[0], 0});
	while(!pq.empty()) {
		int u = pq.top().second;
		ll val = pq.top().first;
		pq.pop();
		if(val > dst[u]) continue;
		for(auto v: adj[u]) {
			if(dst[u] + v.second < dst[v.first]) {
				dst[v.first] = dst[u] + v.second;
				pq.push({dst[v.first], v.first});
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		cout << dst[i] << " ";
	}
	cout << "\n";
}
