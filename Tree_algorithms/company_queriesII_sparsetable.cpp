#include <bits/stdc++.h>
using namespace std;


int n, q;
vector<vector<int>> adj;
vector<vector<int>> jmp;
vector<int> euler;
vector<int> euler_depth;
vector<int> idx_tab;
int depth[200001];
int pw_tab[20];

void dfs(int v, int u, int dep) {
	// dfs with euler walk
	depth[v] = dep;
	euler.push_back(v);
	euler_depth.push_back(dep);
	for(int i = 0; i < (int)adj[v].size(); ++i) {
		if(adj[v][i] == u) continue;
		dfs(adj[v][i], v, dep + 1);
		euler.push_back(v);
		euler_depth.push_back(dep);
	}
}

void solve() {
	dfs(1, 0, 0);

	// for(int i = 0; i < (int)euler.size(); ++i) {
	// 	cout << euler[i] << " ";
	// }
	// cout << "\n";

	idx_tab = vector<int> (n + 1, -1);
	// index of first emergence of each node in array
	int eu_size = (int)euler.size();
	for(int i = 0; i < eu_size; ++i) {
		if(idx_tab[euler[i]] == -1) idx_tab[euler[i]] = i;
	}
	// cout << "\n";

	// for(int i = 0; i < (int)idx_tab.size(); ++i) {
	// 	cout << idx_tab[i] << " ";
	// }
	// cout << "\n";

	// create jump table(size of euler walk array * 20(2 ^ 19 > 2e5))
	jmp = vector<vector<int>> (eu_size, vector<int> (20));
	for(int i = eu_size - 1; i >= 0; --i) {
		jmp[i][0] = euler[i];
		for(int j = 1; j < 20; ++j) {
			int offset = pw_tab[j - 1];
			if(i + pw_tab[j] - 1 >= eu_size) break;
			if(depth[jmp[i][j - 1]] < depth[jmp[i + offset][j - 1]]) jmp[i][j] = jmp[i][j - 1];
			else jmp[i][j] = jmp[i + offset][j - 1];
		}
	}

	// for(int i = 1; i <= eu_size; ++i) {
	// 	cout << "i:" << i << " ";
	// 	for(int j = 0; j < 20; ++j) {
	// 		cout << jmp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	
	int a, b;
	while(q--) {
		cin >> a >> b;
		if(idx_tab[a] > idx_tab[b]) {
			int tmp = b;
			b = a;
			a = tmp;
		}
		int pw = floor(log2(idx_tab[b] - idx_tab[a] + 1));
		int idx1 = jmp[idx_tab[a]][pw];
		int idx2 = jmp[idx_tab[b] - pw_tab[pw] + 1][pw];
		if(depth[idx1] < depth[idx2]) cout << idx1 << "\n";
		else cout << idx2 << "\n";
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> q;
	adj = vector<vector<int>> (n + 1);
	int v;
	for(int i = 2; i <= n; ++i) {
		cin >> v;
		adj[i].push_back(v);
		adj[v].push_back(i);
	}

	pw_tab[0] = 1;
	for(int i = 1; i < 20; ++i) {
		pw_tab[i] = pw_tab[i - 1] + pw_tab[i - 1];
	}
	solve();
}
