#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
vector<int> arr;
ll dp[5001][5001];


void solve() {
	for(int i = 0; i < n; ++i) {
		for(int j = 1; j <= n - i; ++j) {
			if(i == 0) {
				dp[j][j + i] = arr[j - 1];
			}
			else if(i == 1) {
				dp[j][j + i] = max(arr[j - 1], arr[j]);
			}
			else {
				dp[j][j + i] = max(arr[j - 1] + min(dp[j + 2][j + i], dp[j + 1][j + i - 1]), arr[j + i - 1] + min(dp[j + 1][j + i - 1], dp[j][j + i - 2]));
			}
		}
	}
	// for(int i = 1; i <= n; ++i) {
	// 	for(int j = 1; j <= n; ++j) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	cout << dp[1][n] << "\n";
}


int main()
{
	cin >> n;
	int a;
	for(int i = 0; i < n; ++i) {
		cin >> a;
		arr.push_back(a);
	}
	solve();
}
