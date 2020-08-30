#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
const int pw = 30;

int n, q;
int par[mxN];
int tab[mxN][pw];



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;
	for(int i = 0; i < n; ++i) {
		int t;
		cin >> t, --t;
		par[i] = t;
	}

	memset(tab, -1, sizeof(tab));
	for(int i = 0; i < pw; ++i) {
		for(int j = 0; j < n; ++j) {
			if(i == 0) {
				tab[j][0] = par[j];
				continue;
			}
			if(~tab[j][i - 1]) {
				int p = tab[j][i - 1];
				tab[j][i] = tab[p][i - 1];
			}
		}
	}
	while(q--) {
		int x, k;
		cin >> x >> k, --x;
		int jmp = 0;
		while(k > 0) {
			if(k & 1) x = tab[x][jmp];
			k >>= 1;
			++jmp;
		}
		cout << x + 1 << "\n";
	}
}
