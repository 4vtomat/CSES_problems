#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> dp;


void solve() {
	for(int i = 1; i <= n; ++i) {
		if(i < 10) {
			dp[i] = 1;
			continue;
		}
		int mn = 1e9;
		int tmp = i;
		while(tmp > 0) {
			mn = min(mn, dp[i-tmp%10]);
			tmp /= 10;
		}
		dp[i] = mn + 1;
	}
	cout << dp[n] << "\n";
}

int main()
{
	cin >> n;
	dp = vector<int> (1000001, 1e9);
	solve();
}
