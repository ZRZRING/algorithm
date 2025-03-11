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
	std::string s;
	std::cin >> s;
	int n = s.length(), odd = 0, even = 0;
	int64 ans = 0;
	for (int i = 0; i < n; i++) {
		even++;
		// printf("%d %d\n", odd, even);
		if (s[i] == '1') {
			ans += 1ll * odd * (n - i); odd += even; even = 0;
		} else {
			ans += 1ll * even * (n - i); even += odd; odd = 0;
		}
		// printf("%lld\n", ans);
	}
	for (int i = 1; i <= n; i++) {
		ans += 1ll * i * (n - i + 1);
	}
	printf("%lld\n", ans);
}

int main() {
	int T = read();
	while (T--) solve();
	return 0;
}