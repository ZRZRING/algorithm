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

int gcd(int x, int y) {
	if (x < y) std::swap(x, y);
	return y ? gcd(y, x % y) : x;
}

int main() {
	int T = read();
	while (T--) {
		int n = read();
		std::vector<PII> a(n);
		for (auto &x : a) x.first = read();
		for (auto &x : a) x.second = read();
		bool flag = 0; PII t = {0, 0};
		for (int i = 0; i < n; i++) {
			int d = gcd(a[i].first, a[i].second);
			if (d) a[i].first /= d, a[i].second /= d; else continue;
			if (t.first || t.second) {
				flag |= (a[i].first % 2 != t.first % 2 || a[i].second % 2 != t.second % 2);
			}
			t = a[i];
		}
		printf(flag ? "NO\n" : "YES\n");
	}
	return 0;
}