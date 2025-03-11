#include <bits/stdc++.h>

using int64 = long long;

void solve() {
	std::string s;
	std::cin >> s;
	int n = s.length();
	int flag = 0;
	for (int len = 1; len < n; len++) {
		if (n % len != 0) continue;
		std::vector t(0, std::string());
		std::string p;
		for (int i = 0; i < n; i++) {
			p.push_back(s[i]);
			if (i % len == len - 1) {
				t.push_back(p);
				p.clear();
			}
		}
		// for (auto p : t) {
		// 	std::cout << p << '\n';
		// }
		std::set<std::string> S;
		for (auto p : t) {
			S.insert(p);
		}
		if (S.size() == 1) {
			flag = 1;
			break;
		}
		if (S.size() == 2) {
			t.clear();
			for (auto p : S) {
				t.push_back(p);
			}
			int p1 = 0, p2 = 0, p3 = 0;
			for (int i = 0; i < len; i++) {
				if (t[0][i] != t[1][i]) {
					if (!p1) p1 = i;
					else if (!p2) p2 = i;
					else p3 = 1;
				}
			}
			if (p3) continue;
			std::swap(t[0][p1], t[0][p2]);
			if (t[0][p1] == t[1][p1] && t[0][p2] == t[1][p2]) {
				flag = 1;
			}
		}
		if (S.size() == 3) {
			t.clear();
			for (auto p : S) {
				t.push_back(p);
			}
			int p1 = 0, p2 = 0, p3 = 0;
			for (int i = 0; i < len; i++) {
				if (t[0][i] != t[1][i] || t[0][i] != t[2][i]) {
					if (!p1) p1 = i;
					else if (!p2) p2 = i;
					else p3 = 1;
				}
			}
			if (p3) continue;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					std::swap(t[i][p1], t[j][p2]);
					if (t[0][i] == t[1][i] && t[0][i] == t[2][i]) {
						flag = 1;
					}
					std::swap(t[i][p1], t[j][p2]);
				}
			}
		}
		if (S.size() > 3) continue;
		if (flag) break;
	}
	if (flag) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}

int main() {
	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}