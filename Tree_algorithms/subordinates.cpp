#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
int ans[200001];

int dfs(int v, int u) {
	int chld_cnt = 0;
	for(auto& it: adj[v]) {
		if(it == u) continue;
		chld_cnt += dfs(it, v);
	}
	ans[v] = chld_cnt;
	return chld_cnt + 1;
}
		
void solve() {
	dfs(1, 0);
	for(int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}


int main()
{
	cin >> n;
	adj = vector<vector<int>> (n + 1);
	int v;
	for(int i = 2; i <= n; ++i) {
		cin >> v;
		adj[v].push_back(i);
		adj[i].push_back(v);
	}
	solve();
}
