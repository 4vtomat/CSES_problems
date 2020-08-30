#include <bits/stdc++.h>
using namespace std;


int n;
vector<vector<int>> adj;
int ans, ans_idx;

void dfs(int v, int u, int dep) {
	for(int i = 0; i < (int)adj[v].size(); ++i) {
		if(adj[v][i] == u) continue;
		dfs(adj[v][i], v, dep + 1);
	}
	if(dep > ans) {
		ans = dep;
		ans_idx = v;
	}
}

void solve() {
	dfs(1, 0, 0);
	ans = 0;
	dfs(ans_idx, 0, 0);
	cout << ans << "\n";
}


int main()
{
	cin >> n;
	adj = vector<vector<int>> (n + 1);
	int u, v;
	for(int i = 0; i < n - 1; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	solve();
}
