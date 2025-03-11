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
	int n = read(), G = read();
	std::vector<int> c(n + 1), p(n + 1);
	std::vector<std::vector<int> > s(n + 1);
	std::vector<double> f(G + 1, 1e18);
	for (int i = 1; i <= n; i++) {
		c[i] = read(); p[i] = read();
		s[i].resize(p[i] + 1);
		for (int j = 1; j <= p[i]; j++) s[i][j] = read();
	}
	for (int i = G - 1; i >= 0; i--) {
		for (int j = 1; j <= n; j++) {
			double sum = 0; int cnt = 0;
			for (int k = 1; k <= p[j]; k++) {
				if (!s[j][k]) {cnt++; continue;}
				if (i + s[j][k] < G) sum += f[i + s[j][k]];
			}
			f[i] = std::min(f[i], (sum + p[j] * c[j]) / (p[j] - cnt));
		}
	}
	printf("%lf\n", f[0]);
	return 0;
}