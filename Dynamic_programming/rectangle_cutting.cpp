#include <bits/stdc++.h>
using namespace std;


int a, b;
int dp[501][501];

void swap(int& x, int& y) {
	int tmp = x;
	x = y;
	y = tmp;
}
		

void solve() {
	for(int i = 1; i <= a; ++i) {
		for(int j = i; j <= b; ++j) {
			if(i == j) {
				dp[i][j] = 0;
			}
			else {
				int m = 1e9;
				int rec1_h, rec1_w, rec2_h, rec2_w;
				for(int k = 1; k < i; ++k) {
					rec1_h = j;
					rec1_w = k;
					rec2_h = j;
					rec2_w = i - k;
					if(rec1_h > rec1_w) {
						swap(rec1_h, rec1_w);
					}
					if(rec2_h > rec2_w) {
						swap(rec2_h, rec2_w);
					}
					m = min(m, dp[rec1_h][rec1_w] + dp[rec2_h][rec2_w]);
				}
				for(int k = 1; k < j; ++k) {
					rec1_h = k;
					rec1_w = i;
					rec2_h = j - k;
					rec2_w = i;
					if(rec1_h > rec1_w) {
						swap(rec1_h, rec1_w);
					}
					if(rec2_h > rec2_w) {
						swap(rec2_h, rec2_w);
					}
					m = min(m, dp[rec1_h][rec1_w] + dp[rec2_h][rec2_w]);
				}
				dp[i][j] = 1 + m;
			}
		}
	}
	cout << dp[a][b] << "\n";
}

int main()
{
	cin >> a >> b;
	if(a > b) {
		swap(a, b);
	}
	solve();
}
