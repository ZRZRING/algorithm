#include <bits/stdc++.h>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int flag = 0;
		for (int j = i - 1; j >= 1; j--) {
			for (int k = j + 1; k < i; k++) {
				if (std::gcd(j, k) != 1) flag = 1;
			}
			if (flag) {
				ans = std::max(ans, i - j);
				break;
			}
		}
		if (!flag) {
			ans = std::max(ans, i);
		}
	}
	std::cout << ans << '\n';
}