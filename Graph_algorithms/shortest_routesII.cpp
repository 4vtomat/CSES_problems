#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mxN 500

int n, m, q;
ll dp[mxN + 5][mxN + 5];


int main()
{
	cin >> n >> m >> q;
	memset(dp, 0x3f, sizeof(dp));
	for(int i = 0; i < m; ++i) {
		ll a, b, c;
		cin >> a >> b >> c, --a, --b;
		dp[a][b] = min(dp[a][b], c);
		dp[b][a] = min(dp[b][a], c);
	}

	for(int i = 0; i < n; ++i) {
		dp[i][i] = 0;
	}
	for(int k = 0; k < n; ++k) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(dp[i][k] + dp[k][j] < dp[i][j]) dp[i][j] = dp[i][k] + dp[k][j];
			}
		}
	}

	while(q--) {
		int a, b;
		cin >> a >> b, --a, --b;
		if(dp[a][b] < (1LL << 50)) cout << dp[a][b] << "\n";
		else cout << -1 << "\n";
	}
}
