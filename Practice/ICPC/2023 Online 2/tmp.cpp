#include <bits/stdc++.h>

#define int64 long long

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const double eps = 1e-6;

int main() {
	int T = read();
	while (T--) {
		int n = read();
		std::vector<int> a(n);
		std::vector<long double> p(n);
		for (int i = 0; i <= n - 1; i++) a[i] = read();
		for (int i = 0; i <= n - 1; i++) p[i] = 1.0 * read() / 1e5;
		std::vector<long double> f(n + 1);
		for (int i = 0; i <= n - 1; i++) {
			if (fabs(p[i]) < eps) {
				f[i] = n - i; continue;
			}
			if (a[i] == i) f[i] = 1.0 / p[i];
			else f[i] = p[i] + (1.0 - p[i]) * (f[a[i]] + 1.0);
		}
		for (int i = n - 1; i >= 0; i--) {
			f[i] = std::min(f[i], f[i + 1] + 1.0);
		}
		printf("%.10Lf\n", f[0]);
	}
}