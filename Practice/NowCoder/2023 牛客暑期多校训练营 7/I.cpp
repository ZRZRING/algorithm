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

const int N = 2e5, mod = 998244353, inf = 0x3f3f3f3f, inv_2 = 499122177;

int64 qpow(int64 a, int64 x = mod - 2) {
	int64 res = 1ll;
	while (x) {
		if (x & 1) res = res * a % mod; a = a * a % mod; x >>= 1;
	}
	return res;
}

int main() {
	int n = read();
	std::vector<std::string> s(n + 1, std::string());
	for (int i = 1; i <= n; i++) std::cin >> s[i];
	std::sort(s.begin() + 1, s.end(), [](std::string a, std::string b) {
		return a.size() < b.size();
	});
	// std::cout << endl;
	// for (int i = 1; i <= n; i++) std::cout << s[i] << endl;
	auto solve1 = [&](int l, int r, int n) -> int {
		int m = r - l + 1, vis[n], ans = 0, init = qpow(2, n);
		for (int i = 1; i < 1 << m; i++) {
			bool imp = 0;
			memset(vis, 0, sizeof(vis));
			int c = -1, res = init;
			for (int j = 0; j < m; j++) {
				if (i >> j & 1) {
					for (int k = 0; k < n; k++) {
						if (s[l + j][k] == '?') continue;
						if (s[l + j][k] == '0') {
							if (vis[k] == '0') continue;
							if (vis[k] == '1') {imp = 1; break;}
							vis[k] = '0'; res = 1ll * res * inv_2 % mod;
						}
						if (s[l + j][k] == '1') {
							if (vis[k] == '1') continue;
							if (vis[k] == '0') {imp = 1; break;}
							vis[k] = '1'; res = 1ll * res * inv_2 % mod;
						}
					}
					c = -c;
				}
				if (imp) break;
			}
			if (imp) continue;
			ans = (1ll * c * res % mod + ans + mod) % mod;
		}
		return ans;
	};
	auto solve2 = [&](int l, int r, int n) -> int {
		int m = r - l + 1, ans = 0;
		for (int i = 0; i < 1 << n; i++) {
			bool flag = 0, vis[m];
			memset(vis, 0, sizeof(vis));
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < n; k++) {
					if (s[l + j][k] == '?') continue;
					if (s[l + j][k] - '0' != (i >> k & 1)) vis[j] = 1;
				}
			}
			for (int j = 0; j < m; j++) if (!vis[j]) {ans++; break;}
		}
		return ans % mod;
	};
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int x = i;
		while (x < n && s[x + 1].size() == s[x].size()) x++;
		if (x - i + 1 < s[x].size()) ans += solve1(i, x, s[x].size());
		else ans += solve2(i, x, s[x].size());
		ans %= mod; i = x;
	}
	printf("%d", ans);
	return 0;
}