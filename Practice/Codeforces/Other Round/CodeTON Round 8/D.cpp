#include <bits/stdc++.h>

using int64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define PII std::pair<int64, int64>
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

template <class T> void MOD(T &x) {x = x % mod;}
template <class T> int64 abs(T x) {return x < 0 ? -x : x;}
template <class T> int64 lg(T x) {return (int)log10(x);}
template <class T> int64 log(T x) {return (int)log2(x);}

int solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<std::vector<int>> val(n + 2, std::vector<int>(n + 2));
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			std::cin >> val[i][j];
		}
	}
	std::vector<std::vector<int>> f(n + 1);
	f[0].push_back(0);
	for (int i = 1; i <= n; i++) {
		std::priority_queue<std::array<int, 3>> t;
		// std::cout << i << endl;
		t.push({val[1][i], 0, 0});
		for (int j = 0; j <= i - 1; j++) {
			t.push({f[j][0] + val[j + 2][i], j, 0});
		}
		while (!t.empty() && f[i].size() < k) {
			auto [x, j, c] = t.top();
			// std::cout << x << ' ' << j << ' ' << c << endl;
			t.pop();
			f[i].push_back(x);
			if (c + 1 >= f[j].size()) continue;
			t.push({f[j][c + 1] + val[j + 2][i], j, c + 1});
		}
	}
	for (auto x : f[n]) {
		std::cout << x << ' ';
	}
	std::cout << endl;
	return 0;
}

int main() {
	Fast_IOS;
	int T = 1;
	std::cin >> T;
	while (T--) {
		int t = solve();
		if (t == 0) continue;
		if (t == YES) std::cout << "YES" << endl;
		if (t == NO) std::cout << "NO" << endl;
	}
	return 0;
}
