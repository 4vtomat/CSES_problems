#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
	ll mxpf;
	ll mxsf;
	ll mxs;
	ll sum;
};

int n, m;
vector<int> val;
vector<node> seg;
int c;

void calc(int idx) {
	seg[idx].mxpf = max(seg[idx << 1].mxpf, seg[idx << 1].sum + seg[idx << 1 | 1].mxpf);
	seg[idx].mxsf = max(seg[idx << 1 | 1].mxsf, seg[idx << 1 | 1].sum + seg[idx << 1].mxsf);
	seg[idx].mxs = max({seg[idx << 1].mxs, seg[idx << 1 | 1].mxs, seg[idx << 1].mxsf + seg[idx << 1 | 1].mxpf});
	seg[idx].sum = seg[idx << 1].sum + seg[idx << 1 | 1].sum;
}

void apl(int idx, int v) {
	seg[idx].mxpf = v;
	seg[idx].mxsf = v;
	seg[idx].mxs = v;
	seg[idx].sum = v;
}

void upd(int idx, int v) {
	idx += c;
	apl(idx, v);
	while(idx > 1) {
		idx >>= 1;
		calc(idx);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	val = vector<int> (n);
	c = 1 << (int)ceil(log2(n));
	seg = vector<node> (c << 1);
	for(int i = 0; i < n; ++i) {
		cin >> val[i];
	}
	for(int i = 0; i < n; ++i) {
		apl(i + c, val[i]);
	}
	for(int i = c - 1; i > 0; --i) {
		calc(i);
	}

	while(m--) {
		int k, x;
		cin >> k >> x, --k;
		upd(k, x);
		cout << seg[1].mxs << "\n";
	}
}
