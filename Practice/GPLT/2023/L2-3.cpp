#include <bits/stdc++.h>

using int64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define lg(x) ((int)log10(x))
#define log(x) ((int)log2(x))
#define PII std::pair<int64, int64>
#define abs(x) ((x) < 0 ? -(x) : (x))
#define MOD(x) ((x) = ((x) % mod + mod) % mod)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

int solve() {
	int n;
	std::cin >> n;
	std::vector<int> win((1 << n) + 2), lose((1 << n) + 2);
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < 1 << i - 1; j++) {
			std::cin >> lose[(1 << i - 1) + j];
		}
	}
	std::cin >> win[1];
	if (win[1] < lose[1]) {
		std::cout << "No Solution" << endl;
		return 0;
	}
	#define ls u << 1
	#define rs u << 1 | 1
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 0; j < 1 << i - 1; j++) {
			int u = (1 << i - 1) + j;
			if (lose[u] < std::min(lose[ls], lose[rs])) {
				std::cout << "No Solution" << endl;
				return 0;
			}
			if (lose[u] > std::max(lose[ls], lose[rs])) {
				win[ls] = lose[u];
				continue;
			}
			if (lose[ls] > lose[u]) {
				win[rs] = lose[u];
				lose[u] = lose[ls];
			} else {
				win[ls] = lose[u];
				lose[u] = lose[rs];
			}
		}
	}
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < 1 << i - 1; j++) {
			int u = (1 << i - 1) + j;
			if (win[ls]) {
				win[rs] = win[u];
			} else {
				win[ls] = win[u];
			}
		}
	}
	for (int i = 1 << n - 1; i < 1 << n; i++) {
		std::cout << win[i] << ' ' << lose[i] << ' ';
	}
	std::cout << endl;
	return 0;
}

int main() {
	Fast_IOS;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		int t = solve();
		if (t == 0) continue;
		if (t == YES) std::cout << "YES" << endl;
		if (t == NO) std::cout << "NO" << endl;
	}
	return 0;
}