#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> par;
vector<bool> vis;
queue<int> qu;
stack<int> stk;

bool bfs() {
	while(!qu.empty()) {
		int u = qu.front();
		qu.pop();
		if(u == n - 1) return true;
		for(auto v: adj[u]) {
			if(!vis[v]) {
				par[v] = u;
				vis[v] = 1;
				qu.push(v);
			}
		}
	}
	return false;
}

int main()
{
	cin >> n >> m;
	adj = vector<vector<int>> (n);
	par = vector<int> (n);
	vis = vector<bool> (n);
	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	par[0] = -1;
	qu.push(0);
	vis[0] = 1;
	if(bfs()) {
		int mj = n - 1;
		while(~mj) {
			stk.push(mj + 1);
			mj = par[mj];
		}
		cout << stk.size() << "\n";
		while(!stk.empty()) {
			cout << stk.top() << " ";
			stk.pop();
		}
		cout << "\n";
	}
	else cout << "IMPOSSIBLE" << "\n";
}
