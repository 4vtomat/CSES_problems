#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<string> r;
vector<bool> vis;
int ans;

void dfs(int u, int p = -1) {
	vis[u] = 1;
	for(auto v: adj[u]) {
		if(!vis[v]) dfs(v, u);
	}
}

void psh(int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main()
{
	cin >> n >> m;
	adj = vector<vector<int>> (n * m);
	r = vector<string> (n);
	vis = vector<bool> (n * m);
	for(int i = 0; i < n; ++i) {
		cin >> r[i];
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(r[i][j] == '.') {
				if(i) {
					if(r[i - 1][j] == '.') psh(i * m + j, (i - 1) * m + j);
				}
				if(j) {
					if(r[i][j - 1] == '.') psh(i * m + j, i * m + j - 1);
				}
			}
			else vis[i * m + j] = 1;
		}
	}
	for(int i = 0; i < m * n; ++i) {
		if(!vis[i]) {
			++ans;
			dfs(i);
		}
	}
	cout << ans << "\n";
}
