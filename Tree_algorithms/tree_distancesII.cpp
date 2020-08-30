#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<vector<int>> adj;
int depth[200001];
int total[200001];
ll ans[200001];

int dfs(int v, int u, int dep) {
	depth[v] = dep;
	total[v] = 1;
	for(int i = 0; i < (int)adj[v].size(); ++i) {
		if(adj[v][i] == u) continue;
		total[v] += dfs(adj[v][i], v, dep + 1);
	}
	return total[v];
}

void dfs2(int v, int u, int cnt) {
	for(int i = 0; i < (int)adj[v].size(); ++i) {
		if(adj[v][i] == u) continue;
		int tmp = total[v] - total[adj[v][i]] + cnt;
		ans[adj[v][i]] = ans[v] - total[adj[v][i]] + tmp;
		dfs2(adj[v][i], v, tmp);
	}
}
	

void solve() {
	dfs(1, 0, 0);
	ll sum = 0;
	for(int i = 1; i <= n; ++i) {
		sum += depth[i];
	}
	ans[1] = sum;
	dfs2(1, 0, 0);
	for(int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
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
