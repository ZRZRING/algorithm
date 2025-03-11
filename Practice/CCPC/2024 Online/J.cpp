#include <bits/stdc++.h>

using int64 = long long;

const int64 mod = 998244353;

void solve() {
	int n;
	std::cin >> n;
	int A = 0, B = 0;
	std::vector<int> a(n + 1), b(n + 1), c(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		A ^= a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
		B ^= b[i];
	}
	std::vector<int> p(31);
	for (int i = 1; i <= n; i++) {
		int x = a[i] ^ b[i];
		// std::cout << x << " \n"[i == n];
		for (int j = 30; j >= 0; j--) {
			if (x >> j == 1) {
				if (!p[j]) p[j] = x;
				x ^= p[j];
			}
		}
	}
	int ans = 0;
	// std::cout << A << ' ' << B << '\n';
	// for (int i = 0; i < 4; i++) {
	// 	std::cout << p[i] << " \n"[i == 3];
	// }
	for (int i = 30; i >= 0; i--) {
		if ((A >> i & 1) == (B >> i & 1)) {
			if ((A >> i & 1) == 1) {
				A ^= p[i];
				B ^= p[i];
			}
		} else {
			if (A < B) std::swap(A, B);
			auto cal = [&](int x, int s) -> int {
				for (int i = s; i >= 0; i--) {
					if ((x >> i & 1) == 1) x ^= p[i];
				}
				return x;
			};
			if (p[i]) ans = std::min(cal(A, i - 1), cal(B ^ p[i], i - 1));
			else ans = cal(A, i - 1);
			break;
		}
	}
	if (!ans) ans = A;
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int T = 1;
	std::cin >> T;
	while (T--) {
		solve();
	}
}