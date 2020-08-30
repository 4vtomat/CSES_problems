#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, q;
vector<ll> seg;
vector<ll> lzy;
int dep;

void apl(int idx, ll v) {
	seg[idx] += v;
	if(idx < n) {
		lzy[idx] += v;
		assert(lzy[idx] > 0);
	}
	assert(seg[idx] > 0);
}

void upd(int l, int r, int v) {
	l += n, r += n;
	for(; l < r; l >>= 1, r >>= 1) {
		if(l & 1) apl(l++, v);
		if(r & 1) apl(--r, v);
	}
}

void psh(int idx) {
	for(int i = dep; i > 0; --i) {
		int tmp = idx >> i;
		assert(lzy[tmp] >= 0);
		if(lzy[tmp]) {
			apl(tmp << 1, lzy[tmp]);
			apl(tmp << 1 | 1, lzy[tmp]);
			lzy[tmp] = 0;
		}
	}
}

ll qry(int idx) {
	idx += n;
	psh(idx);
	return seg[idx];
}

int main()
{
	cin >> n >> q;
	dep = floor(log2(n));
	seg = vector<ll> (2 * n);
	lzy = vector<ll> (n);
	for(int i = 0; i < n; ++i) {
		cin >> seg[i + n];
	}
	while(q--) {
		int qq;
		cin >> qq;
		if(qq == 1) {
			int a, b, u;
			cin >> a >> b >> u, --a, --b;
			upd(a, b + 1, u);
		}
		else {
			int k;
			cin >> k, --k;
			cout << (ll)qry(k) << "\n";
		}
	}
}
			
