#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<vector<int>> arr;
ll dp[200001];

bool cmp_func(const vector<int>& a1, const vector<int>& a2) {
	return a1[1] < a2[1];
}

bool cmp_func2(const vector<int>& a1, const vector<int>& a2) {
	return a1[1] < a2[0];
}

void solve() {
	for(int i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1];
		auto lb = lower_bound(arr.begin(), arr.end(), arr[i - 1], cmp_func2);
		if(lb == arr.begin())
			dp[i] = max(dp[i], (ll)arr[i - 1][2]);
		else
			dp[i] = max(dp[i], arr[i - 1][2] + dp[lb - arr.begin()]);
	}
	cout << dp[n] << "\n";
}

int main()
{
	cin >> n;
	arr = vector<vector<int>> (n, vector<int> (3));
	for(int i = 0; i < n; ++i) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	sort(arr.begin(), arr.end(), cmp_func);
	// for(auto& it: arr) {
	// 	cout << it[0] << " " << it[1] << " " << it[2] << "\n";
	// }
	solve();
}
