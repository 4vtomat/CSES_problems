#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mxN = 1e5;
const int mod = 1e9 + 7;

int n, m;
vector<int> adj[mxN];
ll cnt[mxN];
bool vis[mxN];

void dfs(int u) {
	vis[u] = 1;
	for(auto v: adj[u]) {
		if(!vis[v]) dfs(v);
		cnt[u] = (cnt[u] + cnt[v]) % mod;
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
	}
	cnt[n - 1] = 1;
	dfs(0);
	cout << cnt[0] << "\n";
}
