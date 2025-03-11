#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5 + 10, mod = 998244353, inf = 0x3f3f3f3f;

std::vector<PII> solve(std::vector<int> a) {
	int min = std::min_element(a.begin(), a.end()) - a.begin();
	int max = std::max_element(a.begin(), a.end()) - a.begin();
	int n = a.size();
	if (a[min] + a[max] < 0) {
		for (auto &x : a) x = -x;
		std::reverse(a.begin(), a.end());
		auto ans = solve(a);
		for (auto &[x, y] : ans) x = n - 1 - x, y = n - 1 - y;
		return ans;
	}
	int cnt = 0;
	for (auto x : a) if (x < 0) cnt++;
	std::vector<PII> ans;
	if (cnt <= 12) {
		for (int i = 0; i < n; i++) {
			if (a[i] < 0) ans.emplace_back(i, max);
		}
		for (int i = 1; i < n; i++) {
			ans.emplace_back(i, i - 1);
		}
		return ans;
	} else {
		for (int i = 0; i < 5; i++) {
			ans.emplace_back(min, min);
		}
		for (int i = 0; i < n; i++) {
			if (a[i] > 0) ans.emplace_back(i, min);
		}
		for (int i = n - 2; i >= 0; i--) {
			ans.emplace_back(i, i + 1);
		}
		return ans;
	}
}

int main() {
	int T = read();
	while (T--) {
		int n = read();
		std::vector<int> a(n);
		for (int i = 0; i < n; i++) a[i] = read();
		auto ans = solve(a);
		printf("%d\n", ans.size());
		for (auto [x, y] : ans) printf("%d %d\n", x + 1, y + 1);
	}
	return 0;
}