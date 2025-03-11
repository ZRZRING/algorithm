#include <bits/stdc++.h>
#include <windows.h>

using int64 = long long;

#define endl '\n'
#define lg(x) ((int)log10(x))
#define log(x) ((int)log2(x))
#define PII std::pair<int64, int64>
#define rep(x, l, r) for (int x = l; x <= r; x++)
#define abs(x) ((x) < 0 ? -(x) : (x))
#define MOD(x) ((x) = ((x) % mod + mod) % mod)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

std::random_device RD;
std::mt19937_64 gen(RD());
int64 roll(int64 l, int64 r) {
	std::uniform_int_distribution<int64> dist(l, r);
	return dist(gen);
}

struct DATA {
	int n;
	std::vector<int> a;
};

void make(int num) {
	if (num == 0) {
		std::cout << (int)2e5 << '\n';
	} else if (num == 1) {
		std::vector<DATA> data;
		std::vector<int> a;
		auto dfs = [&](auto self, int x, int n, int m) -> void {
			if (x == n) {
				data.push_back((DATA){n, a});
				return;
			}
			for (int i = 0; i < m; i++) {
				a.push_back(i);
				self(self, x + 1, n, m);
				a.pop_back();
			}
		};
		dfs(dfs, 0, 5, 6);
		dfs(dfs, 0, 6, 5);
		std::cout << data.size() << '\n';
		for (auto [n, a] : data) {
			std::cout << n << '\n';
			for (auto x : a) {
				std::cout << x << ' ';
			}
			std::cout << '\n';
		}
	} else if (num == 2) {
		int T = 10000;
		std::cout << T << '\n';
		while (T--) {
			int n = 10, m = 10;
			std::cout << n << '\n';
			for (int i = 1; i <= n; i++) {
				std::cout << roll(0, m) << " \n"[i == n];
			}
		}
	} else if (num <= 5) {
		int T = 20;
		std::cout << T << '\n';
		while (T--) {
			int n = 1e4, m = 1e9;
			std::cout << n << '\n';
			for (int i = 1; i <= n; i++) {
				std::cout << roll(1, m) << " \n"[i == n];
			}
		}
	} else {
		int T = 1;
		std::cout << T << '\n';
		int n = 2e5, m = 1e9;
		std::cout << n << '\n';
		for (int i = 1; i <= n; i++) {
			std::cout << roll(1, m) << " \n"[i == n];
		}
	}
}

int main() {
	system("g++ std.cpp -o std");
	for (int i = 0; i <= 0; i++) {
		std::string input_file = std::to_string(i) + ".in";
		std::string output_file = std::to_string(i) + ".out";
		freopen(input_file.c_str(), "w", stdout);
		make(i);
		fclose(stdout);
		std::string run = "std.exe < " + input_file + " > " + output_file;
		system(run.c_str());
	}
	return 0;
}