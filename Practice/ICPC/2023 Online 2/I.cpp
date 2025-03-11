#include <bits/stdc++.h>

#define int64 long long

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const long double eps = 1e-10;

int main() {
	int T = read();
	while (T--) {
		int n = read();
		std::vector<int> a(n);
		std::vector<long double> p(n);
		for (int i = 0; i <= n - 1; i++) a[i] = read();
		for (int i = 0; i <= n - 1; i++) p[i] = read() / 1e5;
		std::vector<long double> f(n + 1, 0);
		for (int i = n - 1; i >= 0; i--) {
			if (p[i] == 0) {
				f[i] = f[i + 1] + 1;
			} else {
				f[i] = std::min(f[i + 1] + 1.0, (i - a[i] + 1) / p[i] - i + a[i]);
			}
		}
		printf("%.12Lf\n", f[0]);
	}
}