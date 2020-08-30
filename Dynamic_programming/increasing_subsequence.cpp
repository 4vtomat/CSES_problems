#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
vector<int> dp;

void solve() {
	dp.push_back(arr[0]);
	for(int i = 1; i < n; ++i) {
		auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
		if(it == dp.end()) {
			dp.push_back(arr[i]);
			continue;
		}
		*it = arr[i];
	}
	cout << dp.size() << "\n";
}

int main()
{
	cin >> n;
	int a;
	for(int i = 0; i < n; ++i) {
		cin >> a;
		arr.push_back(a);
	}
	solve();
}
