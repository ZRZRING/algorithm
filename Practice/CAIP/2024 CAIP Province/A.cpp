#include <bits/stdc++.h>

#define endl '\n'
#define int64 long long

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(60);
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;
		if (x >= 35) {
			if ((m + i - 1) % 7 == 4) {
				ans1++;
			} else {
				ans2++;
			}
		}
	}
	std::cout << ans2 << ' ' << ans1 << endl;
}
