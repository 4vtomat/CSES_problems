#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mxN = 2e5;

int n, m;
vector<int> adj[mxN];
int dst[mxN], chld[mxN], vis[mxN];

void dfs(int u) {
	vis[u] = 1;
	for(auto v: adj[u]) {
		if(!vis[v]) dfs(v);
		if(dst[v] != -1 && dst[v] >= dst[u]) {
			dst[u] = dst[v] + 1;
			chld[u] = v;
		}
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

	memset(dst, -1, sizeof(dst));
	dst[n - 1] = 1;
	dfs(0);
	if(dst[0] == -1) {
		cout << "IMPOSSIBLE" << "\n";
		return 0;
	}
	cout << dst[0] << "\n";
	int tmp = 0;
	while(tmp != n - 1) {
		cout << tmp + 1 << " ";
		tmp = chld[tmp];
	}
	cout << tmp + 1 << "\n";
}
