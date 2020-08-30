#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<vector<int>> seg;

void upd2(int y, int x) {
	while(x > 1) {
		x >>= 1;
		seg[y][x] = seg[y][x << 1] + seg[y][x << 1 | 1];
	}
}

void upd(int y, int x) {
	y += n; x += n;
	seg[y][x] = !seg[y][x];
	upd2(y, x);
	while(y > 1) {
		y >>= 1;
		seg[y][x] = seg[y << 1][x] + seg[y << 1 | 1][x];
		upd2(y, x);
	}
}

int qry(int y1, int x1, int y2, int x2) {
	y1 += n, x1 += n, y2 += n, x2 += n;
	int ret = 0;
	for(; y1 < y2; y1 >>= 1, y2 >>= 1) {
		if(y1 & 1) {
			int xx1 = x1, xx2 = x2;
			for(; xx1 < xx2; xx1 >>= 1, xx2 >>= 1) {
				if(xx1 & 1) ret += seg[y1][xx1++];
				if(xx2 & 1) ret += seg[y1][--xx2];
			}
			++y1;
		}
		if(y2 & 1) {
			int xx1 = x1, xx2 = x2;
			--y2;
			for(; xx1 < xx2; xx1 >>= 1, xx2 >>= 1) {
				if(xx1 & 1) ret += seg[y2][xx1++];
				if(xx2 & 1) ret += seg[y2][--xx2];
			}
		}
	}
	return ret;
}


int main()
{
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
		int qq;
		cin >> qq;
		if(qq == 1) {
			int y, x;
			cin >> y >> x, --y, --x;
			upd(y, x);
		}
		else {
			int y1, x1, y2, x2;
			cin >> y1 >> x1 >> y2 >> x2, --y1, --x1;
			cout << qry(y1, x1, y2, x2) << "\n";
		}
	}
}
