#include <bits/stdc++.h>
#include <windows.h>

using int64 = long long;

const int64 mod = 998244353;

#define endl '\n'
#define lg(x) ((int)log10(x))
#define log(x) ((int)log2(x))
#define PII std::pair<int64, int64>
#define abs(x) ((x) < 0 ? -(x) : (x))
#define MOD(x) ((x) = ((x) % mod + mod) % mod)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

std::random_device RD;
std::mt19937_64 gen(RD());
int64 roll(int64 l, int64 r) {
	std::uniform_int_distribution<int64> dist(l, r);
	return dist(gen);
}

void file(int x) {
	freopen((std::to_string(x) + ".in").c_str(), "w", stdout);
}

int main() {
	for (int i = 2; i <= 2; i++) {
		file(i);
		int T = 20000;
		std::cout << T << '\n';
		while (T--) {
			int64 n = roll(1, 10), k = roll(1, 64);
			std::cout << n << ' ' << k << '\n';
			for (int i = 1; i <= n; i++) {
				std::cout << roll(1, 64) << " \n"[i == n];
			}
		}
	}
	for (int i = 3; i <= 4; i++) {
		file(i);
		int T = 200;
		std::cout << T << '\n';
		while (T--) {
			int64 n = roll(1, 1000), k = roll(1, 65535);
			std::cout << n << ' ' << k << '\n';
			for (int i = 1; i <= n; i++) {
				std::cout << roll(1, 65535) << " \n"[i == n];
			}
		}
	}
	for (int i = 5; i <= 7; i++) {
		file(i);
		int T = 10;
		std::cout << T << '\n';
		while (T--) {
			int64 n = roll(1, 20000), k = roll(1, 1e18);
			std::cout << n << ' ' << k << '\n';
			for (int i = 1; i <= n; i++) {
				std::cout << roll(1, 1e18) << " \n"[i == n];
			}
		}
	}
	for (int i = 8; i <= 12; i++) {
		file(i);
		int T = 2;
		std::cout << T << '\n';
		while (T--) {
			int64 n = roll(1, 100000), k = roll(1, 1e18);
			std::cout << n << ' ' << k << '\n';
			for (int i = 1; i <= n; i++) {
				std::cout << roll(1, 1e18) << " \n"[i == n];
			}
		}
	}
	for (int i = 13; i <= 20; i++) {
		file(i);
		int T = 1;
		std::cout << T << '\n';
		while (T--) {
			int64 n = roll(1, 2e5), k = roll(1, 1e18);
			std::cout << n << ' ' << k << '\n';
			for (int i = 1; i <= n; i++) {
				std::cout << roll(1, 1e18) << " \n"[i == n];
			}
		}
	}
	system("g++ std.cpp -o std");
	for (int i = 1; i <= 20; i++) {
		system(("std.exe < " + std::to_string(i) + ".in > " + std::to_string(i) + ".out").c_str());
	}
	return 0;
}