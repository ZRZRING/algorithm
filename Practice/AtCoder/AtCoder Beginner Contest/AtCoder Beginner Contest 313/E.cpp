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

int main() {
	int n = read();
	std::string s; std::cin >> s;
	bool flag = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] != '1' && s[i - 1] != '1') flag = 1;
	}
	if (flag) {printf("-1"); return 0;}
	int ans = 1;
	for (int i = n - 2; i >= 0; i--) {
		ans = (1ll * ans * (s[i + 1] - '1') % mod + ans + 1) % mod;
	}
	printf("%d\n", (ans + mod - 1) % mod);
	return 0;
}