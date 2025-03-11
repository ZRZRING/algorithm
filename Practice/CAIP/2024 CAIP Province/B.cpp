#include <bits/stdc++.h>

#define endl '\n'
#define int64 long long

int main() {
	int n, m = 20;
	std::cin >> n;
	std::vector<int> a(21);
	std::vector<int> s(21);
	s = {0, 12, 9, 7, 5, 4, 3, 3, 2, 2, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x, y;
			std::cin >> x >> y;
			a[j] += s[x] + y;
		}
	}
	for (int i = 1; i <= 20; i++) {
		std::cout << i << ' ' << a[i] << endl;
	}
}
