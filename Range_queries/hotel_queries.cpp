#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> h, r;
vector<int> seg;
int c;

int qry(int v, int& idx) {
	int ii = 1;
	while(ii < c) {
		if(seg[ii << 1] >= v) ii <<= 1;
		else if(seg[ii << 1 | 1] >= v) ii = ii << 1 | 1;
		else return -1;
	}
	// check the case ii == 1, because it didn't get into while loop
	if(seg[ii] < v) return -1;
	idx = ii - c;
	return seg[ii];
}

void upd(int idx, int v) {
	idx += c;
	seg[idx] += v;
	while(idx > 1) {
		idx >>= 1;
		seg[idx] = max(seg[idx << 1], seg[idx << 1 | 1]);
	}
}

int main()
{
	cin >> n >> m;
	h = vector<int> (n);
	r = vector<int> (m);
	for(int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	for(int i = 0; i < m; ++i) {
		cin >> r[i];
	}
	c = pow(2, ceil(log2(n)));
	seg = vector<int> (2 * c);
	for(int i = 0; i < n; ++i) {
		seg[i + c] = h[i];
	}
	for(int i = c - 1; i > 0; --i) {
		seg[i] = max(seg[i << 1], seg[i << 1 | 1]);
	}
	for(int i = 0; i < m; ++i) {
		int idx;
		int qq = qry(r[i], idx);
		// cout << idx << " " << qq << "\n";
		if(~qq) {
			cout << idx + 1 << " ";
			upd(idx, -r[i]);
			// r[i] = seg[idx + c];
		}
		else cout << 0 << " ";
	}
}
