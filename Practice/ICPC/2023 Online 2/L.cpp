#include <bits/stdc++.h>

#define int64 long long
#define PII std::pair<int, int>
#define l first
#define r second

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int64 mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	int T = read();
	while (T--) {
		std::string s;
		std::cin >> s;
		int n = s.length();
		s = " " + s;
		std::map<int64, std::vector<PII> > mp;
		std::vector<long long> hash(n + 1), P(n + 1);
		P[0] = 1;
		for (int i = 1; i <= n; i++) P[i] = P[i - 1] * 13331 % mod;
		auto gethash = [&](int l, int r) -> long long {
			return (hash[r] - hash[l - 1] * P[r - l + 1] % mod + mod) % mod;
		};
		hash[1] = s[1];
		for (int i = 2; i <= n; i++) {
			hash[i] = (hash[i - 1] * 13331 % mod + s[i]) % mod;
		}
		int64 res = 0;
		for (int p = 1; p < n; p++) {
			int last = 0;
			for (int len = 1; p - len + 1 >= 1 && p + len <= n; len++) {
				int l1 = p - len + 1, r1 = p - last, l2 = p + last + 1, r2 = p + len;
				// printf("%d %d %d %d %lld %lld\n", l1, r1, l2, r2, gethash(l1, r1), gethash(l2, r2));
				if (gethash(l1, r1) == gethash(l2, r2)) {
					res++; last = len;
				}
			}
		}
		printf("%lld\n", res);
	}
}