#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;

int n, m;
vector<int> adj[mxN];
int vis[mxN], grey[mxN];
stack<int> stk;

bool dfs(int u) {
	grey[u] = 1;
	for(auto v: adj[u]) {
		if(grey[v]) return false;
		if(!vis[v] && !dfs(v)) return false;
	}
	grey[u] = 0;
	vis[u] = 1;
	stk.push(u + 1);
	return true;
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
	}
	for(int i = 0; i < n; ++i) {
		if(!vis[i] && !dfs(i)) {
			cout << "IMPOSSIBLE" << "\n";
			return 0;
		}
	}
	while(!stk.empty()) {
		cout << stk.top() << " ";
		stk.pop();
	}
	cout << "\n";
}
