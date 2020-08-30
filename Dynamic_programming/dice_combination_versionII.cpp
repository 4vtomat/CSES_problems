#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;
ll dp[7][(int)1e6+1];
int n;
ll dp2[7][(int)1e6+1];

int ans(int num) {
	int tmp = 0;
	for(int i = 1; i <= 6; ++i) {
		if(i > num) return tmp;
		if(i == num) return tmp + 1;
		tmp += ans(num - i);
	}
	return tmp;
}

ll rec(int c, int rmn) {
	if(rmn == 0) return 1;
	if(~dp2[c][rmn]) return dp2[c][rmn];
	ll tmp = 0;
	for(int i = c; i <= 6; ++i) {
		if(rmn >= i) {
			tmp += rec(i, rmn - i);
		}
	}
	return dp2[c][rmn] = tmp;
}

void solve() {
	for(int i = 0; i <= 6; ++i) {
		for(int j = 0; j <= n; ++j) {
			if(i == 0 || j == 0) {
				dp[i][j] = 0;
				continue;
			}
			if(i <= j) {
				if(i == j) {
					dp[i][j] = dp[i-1][j] + 1;
				}
				else {
					dp[i][j] = dp[i-1][j] + dp[i][j-i];
				}
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout << dp[6][n] << endl;
}

int main()
{
	cin >> n;
	solve();
	memset(dp2, -1, sizeof(dp2));
	cout << rec(1, n) << endl;
}
