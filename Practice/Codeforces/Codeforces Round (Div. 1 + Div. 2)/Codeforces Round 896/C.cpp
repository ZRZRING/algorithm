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
	int n = read(), m = read();
	if (m == 1) {
		for (int i = 0; i <= n; i++) printf("0\n");
		return;
	}
	printf("%d\n", std::min(n + 1, m));
	std::vector<int> a(2 * m);
	for (int i = 0; i < 2 * m; i++) a[i] = i % m;
	for (int i = 0, j = 0; i < n; i++) {
		j++; if (j == m) j = 1;
		for (int k = j; k < j + m; k++) {
			printf("%d ", a[k]);
		}
		puts("");
	}
}

int main() {
	int T = read();
	while (T--) solve();
	return 0;
}