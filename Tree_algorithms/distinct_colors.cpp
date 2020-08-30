#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> val;
vector<vector<int>> adj;
vector<int> dit, dot;
vector<int> dio;
int t;
vector<vector<pair<int, int>>> qs;
vector<int> seg;
vector<int> ans;

void dfs(int u, int p = -1) {
	dit[u] = t++;
	for(auto v: adj[u]) {
		if(v ^ p) dfs(v, u);
	}
	dot[u] = t;
}

int qry(int l, int r) {
	l += t, r += t;
	int ret = 0;
	for(; l < r; l >>= 1, r >>= 1) {
		if(l & 1) ret += seg[l++];
		if(r & 1) ret += seg[--r];
	}
	return ret;
}

void upd(int idx, int v) {
	idx += t;
	seg[idx] = v;
	while(idx > 0) {
		idx >>= 1;
		seg[idx] = seg[idx << 1] + seg[idx << 1 | 1];
	}
}

int main()
{
	cin >> n;
	val = vector<int> (n);
	for(int i = 0; i < n; ++i) {
		cin >> val[i];
	}

	adj = vector<vector<int>> (n);
	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dit = dot = vector<int> (n);
	dfs(0);
	
	qs = vector<vector<pair<int, int>>> (n);
	dio = vector<int> (n);
	for(int i = 0; i < n; ++i) {
		qs[dot[i] - 1].push_back({i, dit[i]});
		dio[dit[i]] = val[i];
	}

	seg = vector<int> (2 * t);
	for(int i = 0; i < t; ++i) {
		seg[i + t] = 1;
	}
	for(int i = t - 1; i > 0; --i) {
		seg[i] = seg[i << 1] + seg[i << 1 | 1];
	}

	ans = vector<int> (n);
	map<int, int> mp;
	for(int i = 0; i < t; ++i) {
		if(mp.find(dio[i]) != mp.end()) upd(mp[dio[i]], 0);
		mp[dio[i]] = i;
		for(pair<int, int> qq: qs[i]) {
			ans[qq.first] = qry(qq.second, i + 1);
		}
	}
	for(int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}
