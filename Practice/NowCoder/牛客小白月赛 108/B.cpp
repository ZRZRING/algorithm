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
	Fast_IOS;
	std::cin >> T;
}

void solve() {
	std::string s;
	std::cin >> s;
	if (s == "4" || s == "8") {
		std::cout << "YES\n";
		return;
	}
	int odd = 0, vis26 = 0, vis48 = 0;
	for (auto x : s) {
		if ((x - '0') % 2 == 1) {
			odd = 1;
		}
		if (x == '2' || x == '6') {
			vis26++;
		}
		if (x == '4' || x == '8') {
			vis48++;
		}
	}
	if (odd && vis26 || vis48 && vis26 || vis48 >= 2) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}