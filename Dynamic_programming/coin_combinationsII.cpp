#include <bits/stdc++.h>
using namespace std;


int n, x;
vector<int> arr;
int dp[101][1000001];


void solve() {
	int mod = 1e9 + 7;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= x; ++j) {
			if(j < arr[i-1]) {
				dp[i][j] = dp[i-1][j];
				continue;
			}
			if(j == arr[i-1]) {
				dp[i][j] = (dp[i-1][j] + 1) % mod;
			}
			else {
				dp[i][j] = (dp[i-1][j] + dp[i][j-arr[i-1]]) % mod;
			}
		}
	}
	cout << dp[n][x] << "\n";
}

int main()
{
	cin >> n >> x;
	int a;
	for(int i = 0; i < n; ++i) {
		cin >> a;
		arr.push_back(a);
	}
	memset(dp, 0, sizeof(dp));
	solve();
}
