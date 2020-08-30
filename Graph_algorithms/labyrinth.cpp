#include <bits/stdc++.h>
using namespace std;


int n, m;
vector<string> lbr;
queue<pair<int, int>> qu;
map<pair<int, int>, pair<int, int>> par;
stack<char> stk;
pair<int, int> A, B;

bool vld(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m && (lbr[i][j] == '.' || lbr[i][j] == 'B');
}
bool bfs() {
	while(!qu.empty()) {
		pair<int, int> pr = qu.front();
		qu.pop();
		if(pr == B) return true;
		int fi = pr.first, se = pr.second;
		if(vld(fi - 1, se)) {
			par[{fi - 1, se}] = {fi, se};
			qu.push({fi - 1, se});
			lbr[fi - 1][se] = '$';
		}
		if(vld(fi, se - 1)) {
			par[{fi, se - 1}] = {fi, se};
			qu.push({fi, se - 1});
			lbr[fi][se - 1] = '$';
		}
		if(vld(fi + 1, se)) {
			par[{fi + 1, se}] = {fi, se};
			qu.push({fi + 1, se});
			lbr[fi + 1][se] = '$';
		}
		if(vld(fi, se + 1)) {
			par[{fi, se + 1}] = {fi, se};
			qu.push({fi, se + 1});
			lbr[fi][se + 1] = '$';
		}
	}
	return false;
}
	
int main()
{
	cin >> n >> m;
	lbr = vector<string> (n);
	for(int i = 0; i < n; ++i) {
		cin >> lbr[i];
	}
	B = {-1, -1};
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(lbr[i][j] == 'A') A.first = i, A.second = j;
			if(lbr[i][j] == 'B') B.first = i, B.second = j;
		}
	}
	qu.push(A);
	if(bfs()) {
		cout << "YES" << "\n";
		while(B != A) {
			if(B.second == par[B].second) {
				if(B.first == par[B].first - 1) stk.push('U');
				else stk.push('D');
			}
			else {
				if(B.second == par[B].second - 1) stk.push('L');
				else stk.push('R');
			}
			B = par[B];
		}
		cout << stk.size() << "\n";
		while(!stk.empty()) {
			cout << stk.top();
			stk.pop();
		}
		cout << "\n";
	}
	else cout << "NO" << "\n";
}
