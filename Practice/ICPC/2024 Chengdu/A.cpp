#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS \
	std::ios::sync_with_stdio(false), \
	std::cin.tie(0), \
	std::cout.tie(0)

const int64 mod = 998244353;

class ICPC {
public:
	int N, T = 1;

	ICPC() {
		Fast_IOS;
		std::cin >> T;
	}

	void solve() {
		std::string s;
		std::cin >> s;
		int n = s.length();
		if (s[0] == '-') {
			return void(std::cout << "No\n");
		}
		if (s[n - 1] == '-' || s[n - 2] == '-' || s[n - 3] == '-') {
			return void(std::cout << "No\n");
		}
		if (s.find('-') == std::string::npos) {
			return void(std::cout << "No\n");
		}
		int tail = n;
		while (s[tail - 1] == '>') tail--;
		std::vector<int> next(n);
		int last = n;
		for (int i = n - 1; i >= 0; i--) {
			next[i] = last;
			if (s[i] == '>') last = i;
		}
		std::vector<A2> ans;
		int l = 0, r = n;
		while (1) {
			ans.push_back({l, r - l});
			int L = l, R = r;
			r = std::max(tail + 3, r - 3);
			if (next[l] < tail) l = next[l];
			if (L == l && R == r) break;
		}
		std::cout << "Yes\n";
		std::cout << ans.size() << '\n';
		for (auto [x, y] : ans) {
			std::cout << x + 1 << ' ' << y << '\n';
		}
	}
};

int main() {
	ICPC icpc;
	while (icpc.T--) {
		icpc.solve();
	}
	return 0;
}