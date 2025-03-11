#include <bits/stdc++.h>

using int64 = long long;

#define A3 std::array<int64, 3>

int main() {
	int n;
	std::cin >> n;
	std::vector<A3> a(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			std::cin >> a[i][j];
		}
	}
	std::sort(a.begin() + 1, a.end(), [](A3 a, A3 b) {
		return a[0] * b[2] > b[0] * a[2];
	});
	int64 sum = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += a[i][1] - a[i][2] * sum;
		sum += a[i][0];
	}
	std::cout << ans << '\n';
}