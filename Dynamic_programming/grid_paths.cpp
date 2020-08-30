#include <bits/stdc++.h>
using namespace std;

#define mod ((int)1e9 + 7)


int n;
vector<vector<char>> arr;
int dp[1001][1001];


void solve() {
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= n; ++j) {
			if(i == 0 || j == 0) {
				dp[i][j] = 0;
			}
			else if(i == 1 && j == 1 && arr[i - 1][j - 1] == '.') {
				dp[i][j] = 1;
			}
			else {
				if(arr[i - 1][j - 1] == '*') {
					dp[i][j] = 0;
				}
				else {
					dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
				}
			}
		}
	}
	cout << dp[n][n] << "\n";
}


int main()
{
	cin >> n;
	arr = vector<vector<char>> (n, vector<char> (n, 0));
	char a;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> a;
			arr[i][j] = a;
		}
	}
	solve();
}
