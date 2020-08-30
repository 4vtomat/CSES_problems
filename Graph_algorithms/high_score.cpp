#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mxN 2500

int n, m;
ll dp[mxN + 5];
vector<pair<int, int>> adj[mxN + 5];
vector<int> adj2[mxN + 5];
vector<bool> vis, vis2;

void dfs2(int u, int p = -1) {
	vis2[u] = 1;
	for(auto v: adj2[u]) {
		if(!vis2[v]) dfs2(v, u);
	}
}

void dfs(int u, int p = -1) {
	vis[u] = 1;
	for(auto v: adj[u]) {
		if(!vis[v.first]) dfs(v.first, u);
	}
}


int main()
{
	cin >> n >> m;
	vis = vis2 = vector<bool> (n);
	memset(dp, 0xcf, sizeof(dp));
	for(int i = 0; i < m; ++i) {
		ll a, b, c;
		cin >> a >> b >> c, --a, --b;
		adj[a].push_back({b, c});
		adj2[b].push_back(a);
	}
	dfs2(n - 1);
	dfs(0);

	dp[0] = 0;
	for(int k = 0; k < 3 * n; ++k) {
		for(int i = 0; i < n; ++i) {
			for(auto j: adj[i]) {
				ll tmp = dp[j.first];
				dp[j.first] = max(dp[j.first], dp[i] + j.second);
				if(k >= n && tmp < dp[j.first] && vis[j.first] && vis2[j.first]) {
					cout << -1 << "\n";
					return 0;
				}
			}
		}
	}
	cout << dp[n - 1] << "\n";
}
