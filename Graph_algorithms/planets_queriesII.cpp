#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;


int n, q;
vector<int> adj[mxN];
bool vis[mxN], in_cyc[mxN];
int t[mxN], rt[mxN], cyc_grp[mxN], cyc_size[mxN], cyc_dst[mxN];
int cy;
int dit[mxN], dot[mxN], dep[mxN];
int dt;

int cnt;
void dfs(int u) {
	vis[u] = 1;
	dit[u] = dt++;
	for(auto v: adj[u]) {
		if(!~rt[v]) {
			rt[v] = rt[u];
			cyc_grp[v] = cyc_grp[u];
			dep[v] = dep[u] + 1;
			dfs(v);
		}
	}
	dot[u] = dt++;
}

int main()
{
	cin >> n >> q;
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
			cyc_dst[tmp] = cyc.size();
			rt[tmp] = tmp;
			cyc.push_back(tmp);
			cyc_grp[tmp] = cy;
			in_cyc[tmp] = 1;
			tmp = t[tmp];
		}
		cyc_size[cy] = cyc.size();

		for(auto v: cyc) {
			dfs(v);
		}
		cyc.clear();
	}
	// for(int i = 0; i < n; ++i) {
	// 	cout << "i:" << i + 1 << " cyc grp:" << cyc_grp[i] << " in_cyc:" << (in_cyc[i]? 1: 0) << " rt:" << rt[i] + 1 << "\n";
	// }

	while(q--) {
		int a, b;
		cin >> a >> b, --a, --b;
		if(cyc_grp[a] == cyc_grp[b]) {
			if(!(in_cyc[a] || in_cyc[b]) && dit[b] < dit[a] && dot[a] < dot[b]) cout << dep[a] - dep[b] << "\n";
			else if(in_cyc[b]) {
				int ans = cyc_dst[rt[b]] - cyc_dst[rt[a]];
				if(ans < 0) ans += cyc_size[cyc_grp[a]];
				if(!in_cyc[a]) ans += dep[a];
				cout << ans << "\n";
			}
			else if(a == b) cout << 0 << "\n";
			else cout << -1 << "\n";
		}
		else cout << -1 << "\n";
	}
}
