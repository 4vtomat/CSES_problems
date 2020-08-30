#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> x, p;
vector<int> seg;
int c;

void upd(int idx, int v) {
	idx += c;
	seg[idx] += v;
	while(idx > 1) {
		idx >>= 1;
		seg[idx] = seg[idx << 1] + seg[idx << 1 | 1];
	}
}

int qry(int idx) {
	int cnt = idx + 1;
	int tmp = 1;
	while(tmp < c) {
		if(seg[tmp << 1] < cnt) {
			cnt -= seg[tmp << 1];
			tmp = tmp << 1 | 1;
		}
		else {
			tmp = tmp << 1;
		}
	}
	return tmp - c;
}

int main()
{
	cin >> n;
	c = 1 << (int)ceil(log2(n));
	x = p = vector<int> (c);
	seg = vector<int> (c << 1);
	for(int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	for(int i = 0; i < n; ++i) {
		cin >> p[i], --p[i];
	}
	for(int i = 0; i < n; ++i) {
		seg[i + c] = 1;
	}
	for(int i = c - 1; i > 0; --i) {
		seg[i] = seg[i << 1] + seg[i << 1 | 1];
	}

	for(int i = 0; i < n; ++i) {
		int qq = qry(p[i]);
		cout << x[qq] << " ";
		upd(qq, -1);
	}
}
