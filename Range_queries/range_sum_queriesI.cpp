#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, q;
vector<ll> seg;

ll qry(int l, int r) {
	l += n, r += n;
	ll ans = 0;
	for(; l < r; l >>= 1, r >>= 1) {
		if(l & 1) ans += seg[l++];
		if(r & 1) ans += seg[--r];
	}
	return ans;
}

int main()
{
	cin >> n >> q;
	seg = vector<ll> (2 * n);
	for(int i = 0; i < n; ++i) {
		cin >> seg[i + n];
	}
	for(int i = n - 1; i > 0; --i) {
		seg[i] = seg[i << 1] + seg[i << 1 | 1];
	}
	while(q--) {
		int a, b;
		cin >> a >> b;
		cout << qry(a - 1, b) << "\n";
	}
}
