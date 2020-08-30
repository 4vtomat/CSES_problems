#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

int n, q;
tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> st;
vector<int> val;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	val = vector<int> (n);
	for(int i = 0; i < n; ++i) {
		cin >> val[i];
		st.insert({val[i], i});
	}

	while(q--) {
		char qq;
		cin >> qq;
		if(qq == '!') {
			int k, x;
			cin >> k >> x, --k;
			st.erase({val[k], k});
			val[k] = x;
			st.insert({val[k], k});

		}
		else {
			int a, b;
			cin >> a >> b;
			cout << st.order_of_key({b + 1, 0}) - st.order_of_key({a, 0}) << "\n";
		}
	}
}
