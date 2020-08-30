#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mxN = 1e5;

int n, m, k;
vector<pair<int, int>> adj[mxN];
vector<ll> dst[mxN];


int main()
{
	cin >> n >> m >> k;
	for(int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c, --a, --b;
		adj[a].push_back({b, c});
	}

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.push({0, 0});
	while(!pq.empty()) {
		int u = pq.top().second;
		ll val = pq.top().first;
		pq.pop();
		if((int)dst[u].size() >= k) {
			if(u == n - 1) break;
			continue;
		}
		dst[u].push_back(val);
		for(auto v: adj[u]) {
			pq.push({val + v.second, v.first});
		}
	}
	for(int i = 0; i < k; ++i) {
		cout << dst[n - 1][i] << " ";
	}
	cout << "\n";
}
