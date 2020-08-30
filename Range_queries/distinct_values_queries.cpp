#include <bits/stdc++.h>
using namespace std;


int n, q;
vector<int> val;
vector<vector<pair<int, int>>> qs;
vector<int> seg;
vector<int> ans;

int qry(int l, int r) {
	l += n, r += n;
	int ret = 0;
	for(; l < r; l >>= 1, r >>= 1) {
		if(l & 1) ret += seg[l++];
		if(r & 1) ret += seg[--r];
	}
	return ret;
}

void upd(int idx, int v) {
	idx += n;
	seg[idx] = v;
	while(idx > 0) {
		idx >>= 1;
		seg[idx] = seg[idx << 1] + seg[idx << 1 | 1];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;
	for(int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		val.push_back(v);
	}

	qs = vector<vector<pair<int, int>>> (n);
	for(int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		qs[b].push_back({i, a});
	}

	seg = vector<int> (2 * n);
	for(int i = 0; i < n; ++i) {
		seg[i + n] = 1;
	}
	for(int i = n - 1; i > 0; --i) {
		seg[i] = seg[i << 1] + seg[i << 1 | 1];
	}
	
	ans = vector<int> (q);
	map<int, int> mp;
	for(int i = 0; i < n; ++i) {
		if(mp.find(val[i]) != mp.end()) upd(mp[val[i]], 0);
		mp[val[i]] = i;
		for(pair<int, int> qq: qs[i]) {
			ans[qq.first] = qry(qq.second, i + 1);
		}
	}
	for(auto a: ans) {
		cout << a << "\n";
	}
}
