#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 1e9 + 7;

template <class T>
T MOD(T& x, int64 p = mod) {
	return x = (x % p + p) % p;
}
template <class T>
T MOD(T&& x, int64 p = mod) {
	return x = (x % p + p) % p;
}

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n, m;
		std::cin >> n >> m;
		std::vector map(n + 2, std::string());
		std::string border(m + 2, '#');
		map[0] = map[n + 1] = border;
		for (int i = 1; i <= n; i++) {
			std::string x;
			std::cin >> x;
			x = "#" + x + "#";
			map[i] = x;
		}
		std::vector f(n + 1, std::vector<int>(m + 1, 0));
		f[1][1] = 1;
		map[1][1] = '#';
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] != '.') continue;
				MOD(f[i][j] = f[i - 1][j] + f[i][j - 1]);
			}
		}
		std::cout << f[n][m] << '\n';
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