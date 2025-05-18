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
	int n = read();
	std::string s;
	std::cin >> s;
	std::vector<int> a(n + 2, 0);
	int cnt = 0;
	for (int i = 0; i < n - i; i++) {
		if (s[i] != s[n - i - 1]) cnt++;
	}
	if (n % 2 == 1) {
		for (int i = cnt; i <= n / 2; i++) {
			a[i] = 1;
		}
		for (int i = n / 2 + 1; i <= n; i++) {
			a[i] = a[n - i];
		}
	} else {
		for (int i = cnt; i <= n / 2; i += 2) {
			a[i] = 1;
		}
		for (int i = n / 2 + 1; i <= n; i++) {
			a[i] = a[n - i];
		}
	}
	for (int i = 0; i <= n; i++) printf("%d", a[i]); puts("");
}

int main() {
	int T = read();
	while (T--) solve();
	return 0;
}