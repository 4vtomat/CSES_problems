#include <bits/stdc++.h>
using namespace std;

typedef struct node {
	int val;
	int clr;
} node;

int n, m;
vector<vector<int>> adj;
vector<node> vtx;
queue<int> qu;

bool bfs() {
	while(!qu.empty()) {
		int u = qu.front();
		qu.pop();
		for(auto v: adj[u]) {
			if(!~vtx[v].clr) {
				vtx[v].clr = !vtx[u].clr;
				qu.push(v);
			}
			else if(vtx[v].clr == vtx[u].clr) return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	adj = vector<vector<int>> (n);
	vtx = vector<node> (n);
	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 0; i < n; ++i) {
		vtx[i] = {i, -1};
	}
	for(int i = 0; i < n; ++i) {
		if(!~vtx[i].clr) {
			vtx[i].clr = 1;
			qu.push(i);
			if(!bfs()) {
				cout << "IMPOSSIBLE" << "\n";
				return 0;
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		cout << vtx[i].clr + 1 << " ";
	}
	cout << "\n";
}
