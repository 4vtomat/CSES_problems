#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
bool visited[200001];
int ans;

void dfs(int v, int u) {
	for(auto& it: adj[v]) {
		if(it == u) continue;
		dfs(it, v);
	}
	if(!visited[u] && !visited[v]) {
		visited[u] = true;
		visited[v] = true;
		ans++;
	}
}

void solve() {
	dfs(1, 0);
	cout << ans << "\n";
}

int main()
{
	cin >> n;
	adj = vector<vector<int>> (n + 1);
	visited[0] = true;
	int u, v;
	for(int i = 0; i < n - 1; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	solve();
}
