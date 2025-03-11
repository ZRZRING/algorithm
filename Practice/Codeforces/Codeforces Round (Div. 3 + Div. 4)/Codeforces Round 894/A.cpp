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
	int T = read();
	while (T--) {
		int n = read(), m = read();
		std::string s[n + 1];
		for (int i = 1; i <= n; i++) std::cin >> s[i];
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 1; j <= n; j++) {
				if (cnt == 0 && s[j][i] == 'v') {cnt++; break;}
				if (cnt == 1 && s[j][i] == 'i') {cnt++; break;}
				if (cnt == 2 && s[j][i] == 'k') {cnt++; break;}
				if (cnt == 3 && s[j][i] == 'a') {cnt++; break;}
			}
		}
		if (cnt == 4) printf("Yes\n"); else printf("No\n");
	}
	return 0;
}