#include <bits/stdc++.h>
using namespace std;


int n, q;
vector<int> seg;

int qry(int l, int r) {
	l += n, r += n;
	int ans = 1e9;
	for(; l < r; l >>= 1, r >>= 1) {
		if(l & 1) ans = min(ans, seg[l++]);
		if(r & 1) ans = min(ans, seg[--r]);
	}
	return ans;
}

void upd(int idx, int v) {
	idx += n;
	seg[idx] = v;
	while(idx > 0) {
		idx >>= 1;
		seg[idx] = min(seg[idx << 1], seg[idx << 1 | 1]);
	}
}

int main()
{
	cin >> n >> q;
	seg = vector<int> (2 * n);
	for(int i = 0; i < n; ++i) {
		cin >> seg[i + n];
	}
	for(int i = n - 1; i > 0; --i) {
		seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
	}

	while(q--) {
		int qq, a, b;
		cin >> qq >> a >> b;
		if(qq == 1) {
			upd(a - 1, b);
		}
		else {
			cout << qry(a - 1, b) << "\n";
		}
	}
}
