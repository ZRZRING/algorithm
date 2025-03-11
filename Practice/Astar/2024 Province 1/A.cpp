#include <bits/stdc++.h>

#define endl '\n'
#define int64 long long

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n + 1), b(n + 1), c(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i] >> b[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int res = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) c[j] = a[j] / 2 + b[j];
			else c[j] = a[j] + b[j];
		}
		std::sort(c.begin() + 1, c.end());
		int t = m;
		for (int i = 1; i <= n; i++) {
			if (t < c[i]) break;
			t -= c[i];
			res++;
		}
		ans = std::max(ans, res);
	}
	std::cout << ans << endl;
	return 0;
}