#include <bits/stdc++.h>

using int64 = long long;

const int m = 2e5;

#define endl '\n'
#define lg(x) ((int)log10(x))
#define log(x) ((int)log2(x))
#define PII std::pair<int64, int64>
#define abs(x) ((x) < 0 ? -(x) : (x))
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

int64 qpow(int64 a, int64 x = mod - 2) {
	int64 res = 1ll;
	while (x) {
		if (x & 1) {
			res = res * a % mod;
		}
		a = a * a % mod;
		x >>= 1;
	}
	return res;
}

void solve() {
	int n, Q, P;
	std::cin >> n >> Q;
	P = sqrt(m);
	std::vector box(n + 1, std::vector<int>());
	std::vector col(m + 1, std::vector<int>());
	for (int i = 1; i <= n; i++) {
		int t;
		std::cin >> t;
		for (int j = 1; j <= t; j++) {
			int x;
			std::cin >> x;
			col[x].push_back(i);
			box[i].push_back(x);
		}
	}
	// for (int i = 1; i <= 5; i++) {
	// 	for (auto x : col[i]) {
	// 		std::cout << x << " \n"[x == col[i].back()];
	// 	}
	// }
	std::vector<int> big(1), id(m + 1);
	std::vector f(P + 10, std::vector<int>(P + 10));
	for (int i = 1; i <= m; i++) {
		if (col[i].size() >= P) {
			id[i] = big.size();
			big.push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		std::sort(box[i].begin(), box[i].end(), [&](int a, int b) {
			return id[a] > id[b];
		});
	}
	for (auto x : big) {
		for (auto i : col[x]) {
			for (auto y : box[i]) {
				if (!id[y]) break;
				f[id[x]][id[y]]++;
			}
		}
	}
	std::vector<int> ans(Q + 1), vis(m + 1);
	std::vector query(m + 1, std::vector<PII>());
	for (int i = 1; i <= Q; i++) {
		int x, y;
		std::cin >> x >> y;
		if (id[x] && id[y]) {
			ans[i] = f[id[x]][id[y]];
		} else if (id[x]) {
			query[x].push_back({y, i});
		} else if (id[y]) {
			query[y].push_back({x, i});
		} else {
			for (auto t : col[x]) {
				vis[t] = 1;
			}
			for (auto t : col[y]) {
				ans[i] += vis[t];
			}
			for (auto t : col[x]) {
				vis[t] = 0;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		if (!id[i]) continue;
		for (auto x : col[i]) {
			vis[x]++;
		}
		for (auto [x, j] : query[i]) {
			for (auto y : col[x]) {
				ans[j] += vis[y];
			}
		}
		for (auto x : col[i]) {
			vis[x]--;
		}
	}
	for (int i = 1; i <= Q; i++) {
		// std::cout << ans[i] << endl;
		if (ans[i] == 0) std::cout << -1 << endl;
		else std::cout << 1ll * n * qpow(ans[i]) % mod << endl;
	}
}

int main() {
	Fast_IOS;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}