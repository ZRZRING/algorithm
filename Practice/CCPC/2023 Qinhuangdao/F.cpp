#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

template <class T>
T MIN(T& x, T y) {
	return x = std::min(x, y);
}

class WORK {
public:
	int N = 2e5;

	std::vector<int> np, prime;

	WORK() {
		np.resize(N + 1);
		for (int i = 2; i <= N; i++) {
			if (!np[i]) {
				prime.push_back(i);
			}
			for (int j = 0; j < prime.size() && i * prime[j] <= N; j++) {
				np[i * prime[j]] = 1;
				if (i % prime[j] == 0) break;
			}
		}
	}

	void solve() {
		int n;
		std::cin >> n;
		std::vector<int64> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		std::vector f(n + 1, std::vector<int64>(4, 1e9));
		f[1][0] = 1;
		f[1][1] = 1;
		f[1][2] = 0;
		f[1][3] = (a[1] != 1);
		for (int i = 2; i <= n; i++) {

			MIN(f[i][0], f[i - 1][1] + 1);
			if ((a[i - 1] & 1) == 1)
			MIN(f[i][0], f[i - 1][2] + 1);
			MIN(f[i][0], f[i - 1][3] + 1);

			MIN(f[i][1], f[i - 1][0] + 1);
			if ((a[i - 1] & 1) == 0)
			MIN(f[i][1], f[i - 1][2] + 1);

			if (a[i] == 1) {

				MIN(f[i][2], f[i - 1][0]);
				if (!np[a[i - 1] + 1])
				MIN(f[i][2], f[i - 1][2]);
				MIN(f[i][2], f[i - 1][3]);

			} else {

				MIN(f[i][2], f[i - 1][a[i] & 1 ^ 1]);
				if (!np[a[i] + a[i - 1]])
				MIN(f[i][2], f[i - 1][2]);
				if (!np[a[i] + 1])
				MIN(f[i][2], f[i - 1][3]);

				MIN(f[i][3], f[i - 1][0] + 1);
				if (!np[a[i - 1] + 1])
				MIN(f[i][3], f[i - 1][2] + 1);
				MIN(f[i][3], f[i - 1][3] + 1);
				
			}
		}
		std::cout << std::min({f[n][0], f[n][1], f[n][2], f[n][3]}) << '\n';
	}
};

int main() {
	Fast_IOS;
	WORK work;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}