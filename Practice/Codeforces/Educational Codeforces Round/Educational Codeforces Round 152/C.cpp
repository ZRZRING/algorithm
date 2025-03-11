#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5 + 10, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	int T = read();
	while (T--) {
		int n = read(), m = read(), ans = m;
		std::string s;
		std::cin >> s; s = " " + s;
		int p = n, to[2][n + 1];
		memset(to, 0, sizeof(to));
		for (int i = n; i >= 1; i--) {
			if (s[i] == '1') p = i; to[0][i] = p;
		}
		p = 1;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '0') p = i; to[1][i] = p;
		}
		PII data[m + 1];
		for (int i = 1; i <= m; i++) {
			data[i] = {to[0][read()], to[1][read()]};
		}
		sort(data + 1, data + m + 1);
		bool flag = 0;
		for (int i = 1; i <= m; i++) {
			if (data[i] == data[i + 1] || data[i].first >= data[i].second) ans--;
			if (data[i].first >= data[i].second) flag = 1;
		}
		printf("%d\n", ans + flag);
	}
	return 0;
}