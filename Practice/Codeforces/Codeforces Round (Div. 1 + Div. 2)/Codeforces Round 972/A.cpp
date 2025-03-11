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
		std::vector<char> c = {'a', 'e', 'i', 'o', 'u'};
		std::vector<int> cnt(5);
		for (int i = 0; i < n; i++) {
			cnt[i % 5]++;
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < cnt[i]; j++) {
				std::cout << c[i];
			}
		}
		std::cout << '\n';
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