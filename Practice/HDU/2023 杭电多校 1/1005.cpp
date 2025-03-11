#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5 + 10, mod = 998244353, inf = 0x3f3f3f3f;

int mul[N];

int qpow(int a, int x) {
	int res = 1;
	while (x) {
		if (x & 1) res = 1ll * res * a % mod; a = 1ll * a * a % mod; x >>= 1;
	}
	return res;
}

int hash(std::string s, int len) {
	int now = 0, mul = qpow(26, len - 1);
	for (int i = 0; i < len; i++) {
		now = (26ll * now + s[i] - 'a') % mod;
	}
	int ans = now;
	// printf("%d\n", now);
	for (int i = len - 1; i >= 0; i--) {
		now -= s[i] - 'a';
		now = 1ll * now * qpow(26, mod - 2) % mod;
		now = (now + 1ll * (s[i] - 'a') * mul % mod) % mod;
		// printf("%d\n", now);
		ans = std::min(ans, now);
	} 
	return ans;
}

int main() {
	int T = read();
	while (T--) {
		int n = read(), len = read(), H[n + 1];
		mul[0] = 1;
		std::string s[n + 1];
		for (int i = 1; i <= n; i++) std::cin >> s[i];
		for (int i = 1; i <= n; i++) H[i] = hash(s[i], len);
		int Q = read();
		while (Q--) {
			int x = read(), y = read();
			if (H[x] == H[y]) printf("Yes\n"); else printf("No\n");
		}
	}
	return 0;
}