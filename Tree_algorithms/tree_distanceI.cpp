#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
int mx_dep, mx_idx;
int depth[200001];

void dfs(int v, int u, int dep) {
	depth[v] = max(depth[v], dep);
	for(auto& it: adj[v]) {
		if(it == u) continue;
		dfs(it, v, dep + 1);
	}
	if(dep > mx_dep) {
		mx_dep = dep;
		mx_idx = v;
	}
}

void solve() {
	dfs(1, 0, 0);
	memset(depth, 0, sizeof(depth));
	mx_dep = 0;
	dfs(mx_idx, 0, 0);
	dfs(mx_idx, 0, 0);
	for(int i = 1; i <= n; ++i) {
		cout << depth[i] << " ";
	}
	cout << "\n";
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
