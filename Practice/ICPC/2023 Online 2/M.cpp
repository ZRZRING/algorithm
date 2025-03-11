#include <bits/stdc++.h>

#define int64 long long

int main() {
	int T;
	std::cin >> T;
	while (T--) {
		int n;
		std::cin >> n;
		std::vector<double> c(n + 1);
		for (int i = 1; i <= n; i++) {
			double a, b, p;
			std::cin >> a >> b >> p;
			c[i] = a + b * p;
		}
		std::sort(c.begin() + 1, c.end());
		double ans = 0;
		for (int i = 1; i <= n; i++) {
			c[i] += c[i - 1]; ans += c[i];
		}
		printf("%.10lf\n", ans);
	}
}