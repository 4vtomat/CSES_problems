#include <bits/stdc++.h>
using namespace std;

#define mod (int)(1e9 + 7)
typedef long long ll;

int n;
ll dp[501][100000];

void solve() {
	ll sum = 0;
	for(int i = 1; i <= n; ++i) {
		sum += i;
	}
	if(sum % 2 != 0) {
		cout << 0 << "\n";
		return;
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= sum / 2; ++j) {
			if(i > j) dp[i][j] = dp[i - 1][j];
			else if(i == j) dp[i][j] = (dp[i - 1][j] + 1) % (2 * mod);
			else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - i]) % (2 * mod);
		}
	}
	cout << dp[n][sum / 2] / 2 << "\n";
}

int main()
{
	cin >> n;
	solve();
}
