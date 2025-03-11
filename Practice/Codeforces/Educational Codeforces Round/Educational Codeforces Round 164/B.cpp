#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n;
		std::cin >> n;
		std::vector<int> a(n + 2);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		std::vector<int> b = a;
		std::sort(b.begin() + 1, b.begin() + n + 1);
		if (b[1] == b[n]) {
			std::cout << -1 << '\n';
			return;
		}
		int ans = 1e9;
		for (int i = 1; i <= n; i++) {
			if (a[i] != a[1]) continue;
			int j = i;
			while (a[j] == a[1]) j++;
			ans = std::min(ans, j - i);
			i = j - 1;
		}
		std::cout << ans << '\n';
	}
};

int main() {
	Fast_IOS;
	WORK work;
	int T = 1;
	std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}