#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mxN = 2.5e3;

int n, m;
vector<pair<int, int>> adj[mxN];
ll dp[mxN];
int par[mxN];

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c, --a, --b;
		adj[a].push_back({b, c});
	}

	int cy = -1;
	for(int i = 0; i < 2 * n; ++i) {
		for(int u = 0; u < n; ++u) {
			for(auto v: adj[u]) {
				if(dp[u] + v.second < dp[v.first]) {
					dp[v.first] = dp[u] + v.second;
					par[v.first] = u;
					if(i >= n) cy = u;
				}
			}
		}
	}
	bool vis[mxN];
	memset(vis, 0, sizeof(vis));
	stack<ll> stk;
	if(~cy) {
		int tmp = cy;
		while(!vis[tmp]) {
			vis[tmp] = 1;
			tmp = par[tmp];
		}

		int tmp2 = tmp;
		stk.push(tmp + 1);
		tmp = par[tmp];
		while(tmp != tmp2) {
			stk.push(tmp + 1);
			tmp = par[tmp];
		}
		stk.push(tmp2 + 1);

		cout << "YES" << "\n";
		while(!stk.empty()) {
			cout << stk.top() << " ";
			stk.pop();
		}
		cout << "\n";
	}
	else cout << "NO" << "\n";
}
