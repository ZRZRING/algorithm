#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define lg(x) ((int)log10(x))
#define log(x) ((int)log2(x))
#define PII std::pair<int64, int64>
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

void solve() {
	int T;
	std::cin >> T;
	std::vector<std::array<int64, 6> > C;
	while (T--) {
		std::string s;
		std::cin >> s;
		if (s[2] == 'r') { // 圆形
			int64 x, y, r;
			std::string ch;
			std::cin >> x >> y >> r >> ch;
			C.push_back({0, x, y, r, 0, ch[0]});
		}
		if (s[2] == 'c') { // 方形
			int64 x1, y1, x2, y2;
			std::string ch;
			std::cin >> x1 >> y1 >> x2 >> y2 >> ch;
			C.push_back({1, x1, y1, x2, y2, ch[0]});
		}
		if (s[2] == 'n') { // 查询
			int64 x1, y1, x2, y2;
			std::cin >> x1 >> y1 >> x2 >> y2;
			for (int i = y2; i >= y1; i--) {
				for (int j = x1; j <= x2; j++) {
					char ans = '.';
					for (auto [opt, X1, Y1, X2, Y2, ch] : C) {
						if (opt == 0) {
							int64 x = X1, y = Y1, r = X2;
							if ((y - i) * (y - i) + (x - j) * (x - j) <= r * r) {
								ans = ch;
							}
						}
						if (opt == 1 && Y1 <= i && i <= Y2 && X1 <= j && j <= X2) {
							ans = ch;
						}
					}
					std::cout << (char)ans;
				}
				std::cout << endl;
			}
		}
	}
}

int main() {
	Fast_IOS;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}