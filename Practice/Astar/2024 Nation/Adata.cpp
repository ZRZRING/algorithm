#include <bits/stdc++.h>

using int64 = long long;

int main() {
	srand(time(0));
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cout << rand() % 10000 << ' ';
	}
	std::cout << '\n';
	std::vector a(n + 1, std::vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			a[i][j] = a[j][i] = rand() % 100 - 50;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cout << a[i][j] << ' ';
		}
		std::cout << '\n';
	}
}