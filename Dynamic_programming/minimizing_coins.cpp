#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> arr;
vector<vector<int>> dp;
vector<int> dp2;

void solve() {
	for(int i = 1; i <= x; ++i) {
		for(int j = 0; j < n; ++j) {
			if(i < arr[j]) {
				continue;
			}
			if(i == arr[j]) {
				dp2[i] = 1;
				continue;
			}
			// if(x == 2000) cout << dp2[i-arr[j]] << endl;
			dp2[i] = min(dp2[i], 1 + dp2[i - arr[j]]);
		}
	}
	if(dp2[x] >= 1e8) {
		cout << -1 << endl;
		return;
	}
	cout << dp2[x] << endl;
}

// void solve() {
// 	for(int i = 1; i <= n; ++i) {
// 		for(int j = 1; j <= x; ++j) {
// 			if(j < arr[i-1]) {
// 				dp[i][j] = dp[i-1][j];
// 				continue;
// 			}
// 			if(j == arr[i-1]) {
// 				dp[i][arr[i-1]] = 1;
// 				continue;
// 			}
// 			dp[i][j] = min(dp[i-1][j], 1 + dp[i][j - arr[i-1]]);
// 		}
// 	}
// 	if(dp[n][x] >= 1e8) {
// 		cout << -1 << endl;
// 		return;
// 	}
// 	cout << dp[n][x] << endl;
// }


int main()
{
	cin >> n >> x;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	// sort(arr.begin(), arr.end());
	// dp = vector<vector<int>> (101, vector<int> (1e6+1, 1e8));
	dp2 = vector<int> (x + 1, 1e8);
	solve();
}
