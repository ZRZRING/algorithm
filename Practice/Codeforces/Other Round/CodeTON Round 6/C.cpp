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

const int64 mod = 998244353;

void solve() {
	int n = read(), k = read();
	std::vector<PII> a(n + 1);
	std::vector<int> ans(k + 1);
	for (int i = 1; i <= n; i++) {
		a[i] = {read(), i};
	}
	std::sort(a.begin() + 1, a.end());
	std::reverse(a.begin() + 1, a.end());
	for (int i = 1; i <= n; i++) {
		l = std::max(l, a.second);
		r = std::min(r, a.second);
	}
}

int main() {
	int T = read();
	while (T--) solve();
	return 0;
}