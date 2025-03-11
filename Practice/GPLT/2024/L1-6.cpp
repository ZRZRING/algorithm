#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'

int main() {
	int n;
	std::cin >> n;
	std::vector<double> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::vector<int> vis(n + 1);
	int x, t;
	std::cin >> x >> t;
	while (x && t) {
		vis[x] += t;
		std::cin >> x >> t;
	}
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += vis[i] * a[i];
		std::cout << vis[i] << endl;
	}
	printf("%.2lf\n", ans);
}
