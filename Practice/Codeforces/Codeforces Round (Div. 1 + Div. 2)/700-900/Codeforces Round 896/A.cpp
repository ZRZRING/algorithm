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

const int N = 2e5, mod = 998244353, inf = 0x3f3f3f3f;

void solve() {
	int n = read(), a[n + 1];
	std::vector<PII> ans;
	for (int i = 1; i <= n; i++) a[i] = read();
	ans.push_back({1, n});
	ans.push_back({1, n});
	if (n % 2 == 1) {
		ans.push_back({1, n - 1});
		ans.push_back({n - 1, n});
		ans.push_back({n - 1, n});
	}
	printf("%d\n", ans.size());
	for (auto [x, y] : ans) printf("%d %d\n", x, y);
}

int main() {
	int T = read();
	while (T--) solve();
	return 0;
}