#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<pair<int, int>> euler;
vector<pair<int, int>> seg;
vector<int> idx_tab;
int eu_size;

int ct[200001][2];
int ans[200001];

pair<int, int> query(int l, int r) {
	l += eu_size;
	r += eu_size;
	pair<int, int> ret = {1000000, 0};
	for(; l < r; l >>= 1, r >>= 1) {
		if(l & 1) ret = min(ret, seg[l++]);
		if(r & 1) ret = min(ret, seg[--r]);
	}
	return ret;
}

void dfs(int v, int u, int dep) {
	euler.push_back({dep, v});
	for(int i = 0; i < (int)adj[v].size(); ++i) {
		if(adj[v][i] == u) continue;
		dfs(adj[v][i], v, dep + 1);
		euler.push_back({dep, v});
	}
}

int dfs2(int v, int u) {
	int tmp = 0;
	for(int i = 0; i < (int)adj[v].size(); ++i) {
		if(adj[v][i] == u) continue;
		tmp += dfs2(adj[v][i], v) - ct[adj[v][i]][1];
	}
	return ans[v] = ct[v][0] - ct[v][1] + tmp;
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

	idx_tab = vector<int> (n + 1, -1);
	for(int i = 0; i < eu_size; ++i) {
		if(idx_tab[euler[i].second] == -1) idx_tab[euler[i].second] = i;
	}


	int a, b;
	while(m--) {
		cin >> a >> b;
		if(idx_tab[a] > idx_tab[b]) {
			int tmp = b;
			b = a;
			a = tmp;
		}
		ct[b][0]++;
		ct[a][0]++;

		pair<int, int> lca = query(idx_tab[a], idx_tab[b] + 1);
		ct[lca.second][1]++;
	}

	dfs2(1, 0);

	for(int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	adj = vector<vector<int>> (n + 1);
	int u, v;
	for(int i = 0; i < n - 1; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	solve();
}
