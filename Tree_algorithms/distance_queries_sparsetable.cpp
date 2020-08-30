#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<vector<int>> adj;
vector<vector<int>> dp;
vector<int> euler;
vector<int> euler_depth;
vector<int> euler_idx;
vector<int> depth;
int pw_tab[20];

void dfs(int v, int u, int dep) {
	depth[v] = dep;
	euler.push_back(v);
	euler_depth.push_back(dep);
	for(int i = 0; i < (int)adj[v].size(); ++i) {
		if(adj[v][i] == u) continue;
		dfs(adj[v][i], v, dep + 1);
		euler.push_back(v);
		euler_depth.push_back(dep);
	}
}

void solve() {
	depth = vector<int> (n + 1);
	dfs(1, 0, 0);

	int eu_size = (int)euler.size();
	euler_idx = vector<int> (n + 1, -1);
	for(int i = 0; i < eu_size; ++i) {
		if(euler_idx[euler[i]] == -1) euler_idx[euler[i]] = i;
	}
	// cout << endl;
	// cout << "euler depth: ";
	// for(int i = 0; i < eu_size; ++i) {
	// 	cout << euler_depth[i] << " ";
	// }
	// cout << endl;
	// cout << "euler: ";
	// for(int i = 0; i < eu_size; ++i) {
	// 	cout << euler[i] << " ";
	// }
	// cout << endl;
	// cout << "euler idx: ";
	// for(int i = 1; i < n + 1; ++i) {
	// 	cout << euler_idx[i] << " ";
	// }
	// cout << endl;

	dp = vector<vector<int>> (eu_size, vector<int> (20, -1));
	for(int i = eu_size - 1; i >= 0; --i) {
		dp[i][0] = euler_depth[i];
		for(int j = 1; j < 20; ++j) {
			int offset = pw_tab[j - 1];
			if(i + pw_tab[j] - 1 >= eu_size) break;
			if(dp[i][j - 1] < dp[i + offset][j - 1]) dp[i][j] = dp[i][j - 1];
			else dp[i][j] = dp[i + offset][j - 1];
		}
	}
	// cout << endl;
	// for(int i = 0; i < eu_size; ++i) {
	// 	cout << "i:" << i << " ";
	// 	for(int j = 0; j < 20; ++j) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	int a, b;
	while(q--) {
		cin >> a >> b;
		if(euler_idx[a] > euler_idx[b]) {
			int tmp = b;
			b = a;
			a = tmp;
		}
		int lca_dep;
		int pw = log2(floor(euler_idx[b] - euler_idx[a] + 1));
		int dep_a = dp[euler_idx[a]][pw];
		int dep_b = dp[euler_idx[b] - pw_tab[pw] + 1][pw];
		if(dep_a < dep_b) lca_dep = dep_a;
		else lca_dep = dep_b;
		cout << (depth[b] - lca_dep) + (depth[a] - lca_dep) << "\n";
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

	pw_tab[0] = 1;
	for(int i = 1; i < 20; ++i) {
		pw_tab[i] = pw_tab[i - 1] + pw_tab[i - 1];
	}
	solve();
}
