#include <bits/stdc++.h>
using namespace std;


int n, q;
vector<int> arr;
vector<vector<int>> jmp;

void solve() {
	for(int i = 1; i <= n; ++i) {
		jmp[i][0] = arr[i];
		for(int j = 1; j < 20; ++j) {
			int par = jmp[i][j - 1];
			par = jmp[par][j - 1];
			if(!par) break;
			jmp[i][j] = par;
		}
	}
	// for(int i = 0; i <= n; ++i) {
	// 	cout << "i:" << i << "\t";
	// 	for(int j = 0; j < 20; ++j) {
	// 		if(i == 0) {
	// 			cout << j << "\t";
	// 			continue;
	// 		}
	// 		cout << jmp[i][j] << "\t";
	// 	}
	// 	cout << "\n";
	// }
	int x, k;
	while(q--) {
		cin >> x >> k;
		bitset<20> bts(k);
		int par = x;
		for(int i = 0; i < 20; ++i) {
			if(bts[i]) par = jmp[par][i];
			if(!par) break;
		}
		if(par == 0) cout << -1 << "\n";
		else cout << par << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	arr = vector<int> (n + 1);
	jmp = vector<vector<int>> (n + 1, vector<int> (20, 0));

	int a;
	arr[1] = 0;
	for(int i = 2; i <= n; ++i) {
		cin >> a;
		arr[i] = a;
	}
	solve();
}
