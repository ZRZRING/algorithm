#include <bits/stdc++.h>

int main() {
	int n;
	std::cin >> n;
	std::string L, R;
	std::cin >> L >> R;
//	if (L.length() < n) {
//		L = "1";
//		for (int i = 1; i < n; i++) {
//			L += "0";
//		}
//	}
//	if (R.length() > n) {
//		R.clear();
//		for (int i = 0; i < n; i++) {
//			R += "9";
//		}
//	}
//	std::cout << L << '\n' << R << '\n';
	auto stoll = [](std::string s) -> long long {
		long long res = 0;
		for (int i = 0; i < s.length(); i++) {
			res = res * 10 + s[i] - '0';
		}
		return res;
	};
	long long l = stoll(L), r = stoll(R);
	int flag = 0;
	std::string now;
	auto c = [](int x) -> int {
		if (x == 5) {
			return 5;
		}
		if (x % 2 == 0) {
			return 2;
		}
		return 1;
	};
	auto dfs = [&](auto self, int x) -> void {
		if (x == 1) {
			for (int i = 1; i < 10; i++) {
				now.push_back(char(i + '0'));
				self(self, x + 1);
				now.pop_back();
			}
			return;
		}
		if (x == n + 1) {
//			if (now > R) return;
//			if (now < L) return;
			long long Now = stoll(now);
			if (Now < l || Now > r) {
				return;
			}
			std::cout << now << '\n';
			flag = 1;
			return;
		}
		if (x >= 10) {
			long long Now = stoll(now);
			long long D = Now * 10 % x;
			if (D > 9) {
				return;
			}
			now.push_back(char(D + '0'));
			self(self, x + 1);
			now.pop_back();
			return;
		} else {
			for (int i = 0; i < 10; i += c(x)) {
				now.push_back(char(i + '0'));
				if (stoll(now) % x != 0) {
					continue;
				} 
				self(self, x + 1);
				now.pop_back();
			}
			return;
		}
	};
	dfs(dfs, 1);
	if (!flag) {
		std::cout << "No Solution\n";
	}
}
