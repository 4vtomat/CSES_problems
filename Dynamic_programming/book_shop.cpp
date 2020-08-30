#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> price, page;
int dp[1001][100001];


void solve() {
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= x; ++j) {
			if(i == 0 || j == 0) {
				dp[i][j] = 0;
			}
			else if(price[i - 1] > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(page[i - 1] + dp[i - 1][j - price[i - 1]], dp[i - 1][j]);
			}
		}
	}
	cout << dp[n][x] << "\n";
}



int main()
{
	cin >> n >> x;
	int pr, pa;
	for(int i = 0; i < n; ++i) {
		cin >> pr;
		price.push_back(pr);
	}
	for(int i = 0; i < n; ++i) {
		cin >> pa;
		page.push_back(pa);
	}
	memset(dp, 0, sizeof(dp));
	solve();
}
