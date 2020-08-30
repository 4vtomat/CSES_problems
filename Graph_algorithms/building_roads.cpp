#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> ans;
vector<bool> vis;
int cnt;

void dfs(int u, int p = -1) {
	vis[u] = 1;
	for(auto v: adj[u]) {
		if(!vis[v]) dfs(v, u);
	}
}

int main()
{
	cin >> n >> m;
	adj = vector<vector<int>> (n);
	vis = vector<bool> (n);
	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i = 0; i < n; ++i) {
		if(!vis[i]) {
			cnt++;
			ans.push_back(i);
			dfs(i);
		}
	}

	int sz = ans.size();
	cout << sz - 1 << "\n";
	for(int i = 0; i < sz - 1; ++i) {
		cout << ans[i] + 1 << " " << ans[i + 1] + 1 << "\n";
	}
}
