#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> par;
stack<int> stk;
int be, en;

bool dfs(int u, int p = -1) {
	vis[u] = 1;
	par[u] = p;
	for(auto v: adj[u]) {
		if(v == p) continue;
		if(!vis[v]) {
			if(dfs(v, u)) return true;
		}
		else {
			be = v;
			en = u;
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> n >> m;
	adj = vector<vector<int>> (n);
	vis = vector<bool> (n);
	par = vector<int> (n);
	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 0; i < n; ++i) {
		if(!vis[i]) {
			if(dfs(i)) {
				stk.push(be + 1);
				while(en != par[be]) {
					stk.push(en + 1);
					en = par[en];
				}
				cout << stk.size() << "\n";
				while(!stk.empty()) {
					cout << stk.top() << " ";
					stk.pop();
				}
				cout << "\n";
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE" << "\n";
}
