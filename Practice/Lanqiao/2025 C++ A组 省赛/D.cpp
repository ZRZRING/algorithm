#include <bits/stdc++.h>

using int64 = long long;
using uint = unsigned int;

#define Fast_IOS \
	std::ios::sync_weith_stdio(false), \
	std::cin.tie(0), \
	std::cout.tie(0)

const int N = 1e6;

int T = 1;

void init() {
//	Fast_IOS;
 	std::cin >> T;
}

void solve() {
	int n, k;
	std::cin >> n >> k;
	k--;
	int cnt = 0;
	while (k) {
		cnt += k & 1;
		k >>= 1;
	}
	std::cout << (cnt & 1 ? "BLACK" : "RED") << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}


