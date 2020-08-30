#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, q;
vector<int> val;
vector<vector<int>> adj;
vector<int> dit, dot;
vector<ll> seg;
int t;

void dfs(int u, int p) {
	dit[u] = t++;
	for(auto v: adj[u]) {
		if(v ^ p) dfs(v, u);
	}
	dot[u] = t;
}

ll qry(int l, int r) {
	l += t, r += t;
	ll ans = 0;
	for(; l < r; l >>= 1, r >>= 1) {
		if(l & 1) ans += seg[l++];
		if(r & 1) ans += seg[--r];
	}
	return ans;
}

void upd(int idx, int v) {
	idx += t;
	seg[idx] += v;
	while(idx > 0) {
		idx >>= 1;
		seg[idx] = seg[idx << 1] + seg[idx << 1 | 1];
	}
}

void solve() {
	dfs(1, 0);

	seg = vector<ll> (2 * (++t));
	for(int i = 1; i <= n; ++i) {
		seg[dit[i] + t] += val[i];
		seg[dot[i] + t] -= val[i];
	}
	for(int i = t - 1; i > 0; --i) {
		seg[i] = seg[i << 1] + seg[i << 1 | 1];
	}
	
	int qq, s, x;
	while(q--) {
		cin >> qq;
		if(qq == 1) {
			cin >> s >> x;
			upd(dit[s], x - val[s]);
			upd(dot[s], val[s] - x);
			val[s] = x;
		}
		else {
			cin >> s;
			cout << qry(0, dit[s] + 1) << "\n";
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;
	val = dit = dot = vector<int> (n + 1);
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
