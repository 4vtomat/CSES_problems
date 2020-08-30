#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
int dp[101][100001];


void solve() {
	int sum = 0;
	for(int i = 0; i < n; ++i) {
		sum += arr[i];
	}

	for(int i = 1; i <= n; ++i) {
		dp[i][arr[i - 1]] = 1;
		for(int j = 1; j <= sum - arr[i - 1]; ++j) {
			if(~dp[i - 1][j]) {
				dp[i][j] = 1;
				dp[i][j + arr[i - 1]] = 1;
			}
		}
	}

	int ans_cnt = 0;
	for(int i = 1; i <= sum; ++i) {
		if(~dp[n][i]) {
			ans_cnt++;
		}
	}
	cout << ans_cnt << "\n";

	for(int i = 1; i <= sum; ++i) {
		if(~dp[n][i]) {
			cout << i << " ";
		}
	}
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int a;
	for(int i = 0; i < n; ++i) {
		cin >> a;
		arr.push_back(a);
	}
	memset(dp, -1, sizeof(dp));
	solve();
}
