#include <bits/stdc++.h>
using namespace std;


string s1, s2;
int dp[5001][5001];


void solve() {
	int len1 = (int)s1.length();
	int len2 = (int)s2.length();
	for(int i = 0; i <= len1; ++i) {
		for(int j = 0; j <= len2; ++j) {
			if(i == 0) {
				dp[i][j] = j;
			}
			else if(j == 0) {
				dp[i][j] = i;
			}
			else if(s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
			}
		}
	}
	cout << dp[len1][len2] << "\n";
}

int main()
{
	cin >> s1 >> s2;
	solve();
}
