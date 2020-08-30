#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mxN = 1e5;
const int mod = 1e9 + 7;
#define INF 0x3f3f3f3f

int n, m;
vector<pair<int, int>> adj[mxN];
ll dst[mxN];
int mxd[mxN], mnd[mxN], rt[mxN];
bool vis[mxN];


int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c, --a, --b;
		adj[a].push_back({b, c});
	}

	memset(dst, 0x3f, sizeof(dst));
	memset(mxd, -1, sizeof(mxd));
	memset(mnd, 0x3f, sizeof(mnd));
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	dst[0] = 0;
	rt[0] = 1;
	mnd[0] = 0;
	mxd[0] = 0;
	pq.push({0, 0});
	while(!pq.empty()) {
		int u = pq.top().second;
		ll val = pq.top().first;
		pq.pop();
		if(val > dst[u]) continue;
		for(auto vv: adj[u]) {
			int v = vv.first;
			if(dst[u] + vv.second < dst[v]) {
				dst[v] = dst[u] + vv.second;
				rt[v] = rt[u];
				mnd[v] = mnd[u] + 1;
				mxd[v] = mxd[u] + 1;
				pq.push({dst[v], v});
			}
			else if(dst[u] + vv.second == dst[v]) {
				dst[v] = dst[u] + vv.second;
				rt[v] = (rt[v] + rt[u]) % mod;
				mnd[v] = min(mnd[v], mnd[u] + 1);
				mxd[v] = max(mxd[v], mxd[u] + 1);
			}
		}
	}
	cout << dst[n - 1] << " " << rt[n - 1] << " " << mnd[n - 1] << " " << mxd[n - 1] << "\n";
}
