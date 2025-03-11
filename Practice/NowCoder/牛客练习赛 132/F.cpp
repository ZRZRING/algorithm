#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;
using A3 = std::array<int64, 3>;

#define Fast_IOS \
	std::ios::sync_with_stdio(false), \
	std::cin.tie(0), \
	std::cout.tie(0)

#define abs(x) ((x) < 0 ? -(x) : (x))

const int64 mod = 998244353;

int N = 4e5, T = 1;

std::vector<A3> pt, ptt;

void init() {
	// Fast_IOS;
	std::cin >> T;
	for (int64 i = 1; i <= N; i += 2) {
		for (int64 j = i + 2; i * i + j * j <= 2 * N; j += 2) {
			int64 a = i * j, b = (j * j - i * i) / 2, c = (i * i + j * j) / 2;
			pt.push_back({a, b, c});
			std::sort(pt.back().begin(), pt.back().end());
		}
	}
	for (auto [x, y, z] : pt) {
		for (int64 i = 1; z * i <= N; i++) {
			ptt.push_back({i * x, i * y, i * z});
		}
	}
	std::sort(ptt.begin(), ptt.end());
	// for (int i = 0; i < 10; i++) {
	// 	auto [a, b, c] = ptt[i];
	// 	std::cout << a << ' ' << b << ' ' << c << '\n';
	// }
}

void solve() {
	int64 a, b, c, ans = 1e15;
	std::cin >> a >> b >> c;
	for (auto x : ptt) {
		do {
			ans = std::min(ans, abs(x[0] - a) + abs(x[1] - b) + abs(x[2] - c));
		} while (std::next_permutation(x.begin(), x.end()));
	}
	std::cout << ans << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}