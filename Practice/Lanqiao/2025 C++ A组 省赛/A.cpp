#include <bits/stdc++.h>

using int64 = long long;
using uint = unsigned int;

#define Fast_IOS \
	std::ios::sync_weith_stdio(false), \
	std::cin.tie(0), \
	std::cout.tie(0)

const int N = 1e6;

int T = 1;

std::vector<int> prime, np;

void init() {
//	Fast_IOS;
// 	std::cin >> T;
	np.resize(N + 1);
	for (int i = 2; i <= N; i++) {
		if (!np[i]) {
			prime.push_back(i);
		}
		for (int j = 0; j < prime.size() && i * prime[j] <= N; j++) {
			np[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
}

void solve() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cout << prime[i] << '\n';
	}
	std::cout << prime[n - 1] << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}

