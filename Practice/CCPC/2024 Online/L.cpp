#include <bits/stdc++.h>

using int64 = long long;

const int64 mod = 998244353;

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector a(n, std::string());
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int64 ans = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			if (a[i][j] == 'c' && a[i][j + 1] == 'c' && a[i + 1][j] == 'p' && a[i + 1][j + 1] == 'c') {
				ans++;
			}
		}
	}
	std::cout << ans << '\n';
}