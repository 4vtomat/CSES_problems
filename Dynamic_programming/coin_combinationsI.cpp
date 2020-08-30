#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, x;
vector<int> arr;
int dp[1000001];


void solve() {
	int mod = 1e9 + 7;
	for(int i = 1; i <= x; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(i < arr[j-1]) {
				continue;
			}
			if(i == arr[j-1]) {
				dp[i] = (dp[i] + 1) % mod;
			}
			else {
				dp[i] = (dp[i] + dp[i-arr[j-1]]) % mod;
			}
		}
	}
	cout << dp[x] << "\n";
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
