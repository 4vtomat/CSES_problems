#include <bits/stdc++.h>
using namespace std;


int n, q;
vector<vector<int>> seg;

int qry(int y1, int x1, int y2, int x2) {
	x1 += n, x2 += n;
	y1 += n, y2 += n;
	int ret = 0;
	for(; y1 < y2; y1 >>= 1, y2 >>= 1) {
		if(y1 & 1) {
			for(int t1 = x1, t2 = x2; t1 < t2; t1 >>= 1, t2 >>= 1) {
				if(t1 & 1) ret += seg[y1][t1++];
				if(t2 & 1) ret += seg[y1][--t2];
			}
			++y1;
		}
		if(y2 & 1) {
			--y2;
			for(int t1 = x1, t2 = x2; t1 < t2; t1 >>= 1, t2 >>= 1) {
				if(t1 & 1) ret += seg[y2][t1++];
				if(t2 & 1) ret += seg[y2][--t2];
			}
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> q;
	seg = vector<vector<int>> (2 * n, vector<int> (2 * n));
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for(int j = 0; j < n; ++j) {
			if(s[j] == '*') seg[i + n][j + n] = 1;
		}
	}
	for(int i = n - 1; i > 0; --i) {
		for(int j = 0; j < n; ++j) {
			seg[i][j + n] = seg[i << 1][j + n] + seg[i << 1 | 1][j + n];
		}
	}
	for(int i = 1; i < 2 * n; ++i) {
		for(int j = n - 1; j > 0; --j) {
			seg[i][j] = seg[i][j << 1] + seg[i][j << 1 | 1];
		}
	}

	while(q--) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2, --y1, --x1;
		cout << qry(y1, x1, y2, x2) << "\n";
	}
}
