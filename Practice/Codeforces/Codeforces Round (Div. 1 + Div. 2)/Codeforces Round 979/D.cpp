#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n, Q;
		std::cin >> n >> Q;
		std::vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		int mex = 1;
		std::string P;
		std::cin >> P;
		int m = P.length(), cnt = 0;
		P = " " + P;
		std::vector<int> gap, vis(m + 1);
		for (int i = 1; i <= n; i++) {
			int x = a[i];
			vis[x] = 1;
			while (vis[mex]) mex++;
			if (mex == i + 1) gap.push_back(i);
		}
		auto modify = [&](int l, int r, int t) -> void {
			if (l < 1 || r > m) return;
			if (P[l] == 'L' && P[r] == 'R') {
				auto it = std::lower_bound(gap.begin(), gap.end(), l);
				if (it == gap.end() || *it != l) {
					cnt += t;
				}
			}
		};
		for (int i = 1; i <= m - 1; i++) {
			modify(i, i + 1, 1);
		}
		while (Q--) {
			int x;
			std::cin >> x;
			modify(x, x + 1, -1);
			modify(x - 1, x, -1);
			P[x] = (P[x] == 'L' ? 'R' : 'L');
			modify(x, x + 1, 1);
			modify(x - 1, x, 1);
			std::cout << (cnt == 0 ? "YES" : "NO") << '\n';
		}
	}
};

int main() {
	Fast_IOS;
	WORK work;
	int T = 1;
	std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}