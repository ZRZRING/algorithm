#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS \
	std::ios::sync_with_stdio(false), \
	std::cin.tie(0), \
	std::cout.tie(0)

const int64 mod = 998244353;

int N, T = 1;

void init() {
	// Fast_IOS;
	// std::cin >> T;
}

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> b(n);
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
	}
	std::vector<int> c = b, p(n);
	std::sort(c.begin(), c.end());
	for (int i = 0; i < n; i++) {
		p[i] = std::lower_bound(c.begin(), c.end(), b[i]) - c.begin();
	}
	std::map<int, int> l, r;
	for (int i = 0; i < n; i++) {
		if (!l[c[i]]) {
			int L = c[i], R = c[i];
			std::vector<int> box;
			box.push_back(R);
			int next = box.back() + k;
			auto pos = std::lower_bound(c.begin(), c.end(), next);
			while (pos != c.end() && *pos == next) {
				R = next;
				box.push_back(R);
				next += k;
				pos = std::lower_bound(c.begin(), c.end(), next);
			}
			for (auto x : box) {
				l[x] = L;
				r[x] = R;
			}
		}
	}
	// for (int i = 0; i < n; i++) {
	// 	std::cout << p[i] << ' ';
	// }
	// std::cout << "\n";
	std::vector a(std::min(n, k), std::map<int, std::set<int>>());
	for (int i = 0; i < n; i++) {
		a[i % k][b[i] % k].insert(b[i]);
	}
	for (int i = 0; i < n; i++) {
		if (i % k == p[i] % k) continue;
		if (a[p[i] % k].count(b[i] % k) == 0) {
			std::cout << "No\n";
			return;
		}
		auto S = a[p[i] % k][b[i] % k];
		auto it = S.lower_bound(l[b[i]]);
		if (it == S.end() || *it > r[b[i]]) {
			std::cout << "No\n";
			return;
		}
	}
	std::cout << "Yes\n";
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}