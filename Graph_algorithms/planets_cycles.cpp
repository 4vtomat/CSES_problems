#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;


int n;
vector<int> adj[mxN];
int t[mxN], rt[mxN];
int cyc_grp[mxN], cyc_dst[mxN], cyc_size[mxN];
int cy;
bool vis[mxN], in_cyc[mxN];
int dep[mxN];

void dfs(int u) {
	vis[u] = 1;
	for(auto v: adj[u]) {
		if(!~rt[v]) {
			rt[v] = rt[u];
			dep[v] = dep[u] + 1;
			dfs(v);
		}
	}
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> t[i], --t[i];
		adj[t[i]].push_back(i);
	}

	memset(rt, -1, sizeof(rt));
	for(int i = 0; i < n; ++i) {
		if(~rt[i]) continue;

		int tmp = i;
		while(!vis[tmp]) {
			vis[tmp] = 1;
			tmp = t[tmp];
		}

		vector<int> cyc;
		cy++;
		while(!cyc.size() || tmp ^ cyc[0]) {
			rt[tmp] = tmp;
			cyc_grp[tmp] = cy;
			cyc_dst[tmp] = cyc.size();
			in_cyc[tmp] = 1;
			cyc.push_back(tmp);
			tmp = t[tmp];
		}
		cyc_size[cy] = cyc.size();

		for(auto u: cyc) {
			dfs(u);
		}
	}

	for(int i = 0; i < n; ++i) {
		int ans = cyc_size[cyc_grp[rt[i]]];
		if(!in_cyc[i]) ans += dep[i];
		cout << ans << " ";
	}
	cout << "\n";
}
