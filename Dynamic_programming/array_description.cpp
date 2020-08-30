#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
typedef long long ll;

int n, m;
vector<int> arr;
ll dp[100001][102];


void solve() {
	for(int i = 1; i <= n; ++i) {
		int a = arr[i - 1];
		if(a != 0) {
			if(i == 1) dp[i][a] = 1;
			else dp[i][a] = (dp[i - 1][a - 1] + dp[i - 1][a] + dp[i - 1][a + 1]) % mod;
		}
		else {
			if(i == 1) {
				for(int j = 1; j <= m; ++j) {
					dp[i][j] = 1;
				}
			}
			else {
				for(int j = 1; j <= m; ++j) {
					dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
				}
			}
		}
	}

	int ans = 0;
	for(int i = 1; i <= m; ++i) {
		ans = (ans + dp[n][i]) % mod;
	}
	cout << ans << "\n";
}


int main()
{
	cin >> n >> m;
	int x;
	for(int i = 0; i < n; ++i) {
		cin >> x;
		arr.push_back(x);
	}
	solve();
}
