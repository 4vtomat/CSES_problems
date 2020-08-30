#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<vector<int>> adj;
vector<pair<int, int>> euler;
int eu_size;
vector<pair<int, int>> seg;
vector<int> euler_idx;

pair<int, int> query(int l, int r) {
	l += eu_size;
	r += eu_size;
	pair<int, int> ans = {1000000, 0};
	for(; l < r; l >>= 1, r >>= 1) {
		if(l & 1) ans = min(ans, seg[l++]);
		if(r & 1) ans = min(ans, seg[--r]);
	}
	return ans;
}

void dfs(int v, int u, int dep) {
	euler.push_back({dep, v});
	for(int i = 0; i < (int)adj[v].size(); ++i) {
		if(adj[v][i] == u) continue;
		dfs(adj[v][i], v, dep + 1);
		euler.push_back({dep, v});
	}
}

void solve() {
	dfs(1, 0, 0);

	eu_size = (int)euler.size();
	seg = vector<pair<int, int>> (2 * eu_size);
	for(int i = 0; i < eu_size; ++i) {
		seg[i + eu_size] = euler[i];
	}
	for(int i = eu_size - 1; i > 0; --i) {
		seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
	}

	euler_idx = vector<int> (n + 1, -1);
	for(int i = 0; i < eu_size; ++i) {
		if(euler_idx[euler[i].second] == -1) euler_idx[euler[i].second] = i;
	}


	int a, b;
	while(q--) {
		cin >> a >> b;
		if(euler_idx[a] > euler_idx[b]) {
			int tmp = b;
			b = a;
			a = tmp;
		}
		int dep_a = euler[euler_idx[a]].first;
		int dep_b = euler[euler_idx[b]].first;
		int dep_lca = query(euler_idx[a], euler_idx[b] + 1).first;
		// cout << "lca_dep:" << dep_lca << " dep_a:" << dep_a << " dep_b:" << dep_b << "\n";
		cout << (dep_a - dep_lca) + (dep_b - dep_lca) << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	adj = vector<vector<int>> (n + 1);
	int u, v;
	for(int i = 0; i < n - 1; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	solve();
}
