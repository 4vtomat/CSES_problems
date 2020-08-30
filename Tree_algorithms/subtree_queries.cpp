#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, q;
vector<int> val;
vector<vector<int>> adj;
// dfs in time, dfs out time
vector<int> dit, dot;
vector<int> dio;
int t, d_size;
vector<ll> seg;

void dfs(int v, int u) {
	dit[v] = ++t;
	dio.push_back(v);
	for(auto chld: adj[v]) {
		if(chld ^ u) dfs(chld, v);
	}
	dot[v] = t;
}

ll qry(int l, int r) {
	l += d_size;
	r += d_size;
	ll ans = 0;
	for(; l < r; l >>= 1, r >>= 1) {
		if(l & 1) ans += seg[l++];
		if(r & 1) ans += seg[--r];
	}
	return ans;
}

void upd(int idx, int v) {
	idx += d_size;
	seg[idx] = v;
	while(idx > 0) {
		idx >>= 1;
		seg[idx] = seg[idx << 1] + seg[idx << 1 | 1];
	}
}

void solve() {
	dit = dot = vector<int> (n + 1);
	t = -1;
	dfs(1, 0);

	d_size = dio.size();
	seg = vector<ll> (2 * d_size);
	for(int i = 0; i < d_size; ++i) {
		seg[i + d_size] = val[dio[i]];
	}
	for(int i = d_size - 1; i > 0; --i) {
		seg[i] = seg[i << 1] + seg[i << 1 | 1];
	}

	int qq, s, x;
	while(q--) {
		cin >> qq;
		if(qq == 1) {
			cin >> s >> x;
			upd(dit[s], x);
		}
		else {
			cin >> s;
			cout << qry(dit[s], dot[s] + 1) << "\n";;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	val = vector<int> (n + 1);
	for(int i = 1; i <= n; ++i) {
		cin >> val[i];
	}
	adj = vector<vector<int>> (n + 1);
	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	solve();
}
