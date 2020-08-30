#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> par;
vector<int> cnt;
vector<vector<int>> dp;
vector<int> euler;
vector<int> euler_depth;
vector<int> euler_idx;
vector<int> depth;

int pw_tab[20];
int ct[200001][2];
int ans[200001];

void dfs(int v, int u, int dep) {
	par[v] = u;
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

int dfs2(int v, int u) {
	int tmp = 0;
	for(int i = 0; i < (int)adj[v].size(); ++i) {
		if(adj[v][i] == u) continue;
		tmp += dfs2(adj[v][i], v) - ct[adj[v][i]][1];
	}
	return ans[v] = ct[v][0] - ct[v][1] + tmp;
}

void solve() {
	par = vector<int> (n + 1);
	depth = vector<int> (n + 1);
	euler_idx = vector<int> (n + 1, -1);
	dfs(1, 1, 0);

	int eu_size = (int)euler.size();
	for(int i = 0; i < eu_size; ++i) {
		if(euler_idx[euler[i]] == -1) euler_idx[euler[i]] = i;
	}
	// cout << "euler: ";
	// for(int i = 0; i < eu_size; ++i) {
	// 	cout << euler[i] << " ";
	// }
	// cout << endl;
	// cout << "euler_depth: ";
	// for(int i = 0; i < eu_size; ++i) {
	// 	cout << euler_depth[i] << " ";
	// }
	// cout << endl;
	// cout << "euler_idx: ";
	// for(int i = 1; i <= n; ++i) {
	// 	cout << euler_idx[i] << " ";
	// }
	// cout << endl;

	// cout << "depth: ";
	// for(int i = 1; i <= n; ++i) {
	// 	cout << depth[i] << " ";
	// }
	// cout << endl;

	dp = vector<vector<int>> (eu_size, vector<int> (20, -1));
	for(int i = eu_size - 1; i >= 0; --i) {
		dp[i][0] = euler[i];
		for(int j = 1; j < 20; ++j) {
			int offset = pw_tab[j - 1];
			if(i + pw_tab[j] - 1 >= eu_size) break;
			if(depth[dp[i][j - 1]] < depth[dp[i + offset][j - 1]]) dp[i][j] = dp[i][j - 1];
			else dp[i][j] = dp[i + offset][j - 1];
		}
	}

	// for(int i = 0; i < eu_size; ++i) {
	// 	cout << "i:" << i << " ";
	// 	for(int j = 0; j < 20; ++j) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	cnt = vector<int> (n + 1, 0);
	int a, b;
	while(m--) {
		cin >> a >> b;
		if(euler_idx[a] > euler_idx[b]) {
			int tmp = b;
			b = a;
			a = tmp;
		}
		ct[b][0]++;
		ct[a][0]++;

		int pw = floor(log2(euler_idx[b] - euler_idx[a] + 1));
		int lca;
		int p1 = dp[euler_idx[a]][pw];
		int p2 = dp[euler_idx[b] - pw_tab[pw] + 1][pw];
		if(depth[p1] < depth[p2]) lca = p1;
		else lca = p2;
		ct[lca][1]++;
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
	pw_tab[0] = 1;
	for(int i = 1; i < 20; ++i) {
		pw_tab[i] = pw_tab[i - 1] + pw_tab[i - 1];
	}
	solve();
}
