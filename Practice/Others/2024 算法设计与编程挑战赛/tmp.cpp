#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	int L, Q;
	std::cin >> L >> Q;
	int G = sqrt(n);
	std::vector<int> g(n + 1), val(n + 1), to(n + 1);
	for (int i = 1; i <= n; i++) {
		g[i] = (i - 1) / G;
	}
	for (int i = 1; i <= n; i++) {
		if (g[i] == (n - 1) / G) break;
		int j = i, x = i;
		val[i] = 1;
		while (g[i] == g[j]) {
			j++;
			if (a[j] - a[x] > L) {
				val[i]++;
				x = j;
			}
		}
		to[i] = j;
	}
	// for (int i = 1; i <= n; i++) {
	// 	std::cout << val[i] << ' ' << to[i] << endl;
	// }
	while (Q--) {
		int l, r;
		std::cin >> l >> r;
		if (l > r) std::swap(l, r);
		int res = 0;
		while (g[l] != g[r]) {
			res += val[l];
			l = to[l];
		}
		int x = l;
		if (l != r) res++;
		for (int i = l + 1; i <= r; i++) {
			if (a[i] - a[x] > L) res++;
		}
		std::cout << res << endl;
	}
	return 0;
}