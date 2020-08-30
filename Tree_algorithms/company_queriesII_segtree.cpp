#include <bits/stdc++.h>
using namespace std;


int n, q;
vector<vector<int>> adj;
vector<pair<int, int>> seg;
vector<pair<int, int>> euler;
int eu_size;
vector<int> idx_tab;

pair<int, int> query(int l, int r) {
	l += eu_size;
	r += eu_size;
	pair<int, int> ans = {10000000, 0};
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
		seg[eu_size + i] = euler[i];
	}
	for(int i = eu_size - 1; i > 0; --i) {
		seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
	}

	idx_tab = vector<int> (n + 1, -1);
	for(int i = 0; i < eu_size; ++i) {
		if(idx_tab[euler[i].second] == -1) idx_tab[euler[i].second] = i;
	}

	int a, b;
	while(q--) {
		cin >> a >> b;
		if(idx_tab[a] > idx_tab[b]) {
			int tmp = b;
			b = a;
			a = tmp;
		}
		cout << query(idx_tab[a], idx_tab[b] + 1).second << "\n";
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> q;
	adj = vector<vector<int>> (n + 1);
	int v;
	for(int i = 2; i <= n; ++i) {
		cin >> v;
		adj[i].push_back(v);
		adj[v].push_back(i);
	}

	solve();
}
