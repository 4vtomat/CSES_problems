#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll mod = 1e9 + 7;
vector<ll> dp;

void solve() {
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= 6; ++j) {
			if(j > i) break;
			if(i == j) {
				dp[i] += 1;
				break;
			}
			dp[i] = (dp[i] + dp[i - j]) % mod;
		}
	}
	cout << dp[n] << endl;
}

int main()
{
	cin >> n;
	dp = vector<ll> (n + 1);
	solve();
}
