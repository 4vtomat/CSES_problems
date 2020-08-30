#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;

int n, m;
vector<int> adj[mxN];
int p[mxN], vis[mxN], grey[mxN];
stack<int> stk;

bool dfs(int u) {
	grey[u] = 1;
	for(auto v: adj[u]) {
		if(grey[v]) {
			stk.push(v + 1);
			int tmp = u;
			while(tmp ^ v) {
				stk.push(tmp + 1);
				tmp = p[tmp];
			}
			stk.push(v + 1);
			cout << stk.size() << "\n";
			while(!stk.empty()) {
				cout << stk.top() << " ";
				stk.pop();
			}
			cout << "\n";
			return true;
		}
		else {
			if(!vis[v]) {
				p[v] = u;
				if(dfs(v)) return true;
			}
		}
	}
	grey[u] = 0;
	vis[u] = 1;
	return false;
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
		if(!vis[i] && dfs(i)) return 0;
	}
	cout << "IMPOSSIBLE" << "\n";
}
