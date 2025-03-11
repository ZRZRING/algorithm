#include <bits/stdc++.h>

using int64 = long long;

const int64 mod = 998244353;

#define lowbit(x) ((x) & -(x))

void solve() {
	int n, k;
	std::cin >> n >> k;
	if (lowbit(n) <= k) {
		std::cout << "Alice\n";
	} else {
		std::cout << "Bob\n";
	}
}

int main() {
	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}