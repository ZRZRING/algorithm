#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	int L, Q;
	std::cin >> L >> Q;
	int G = 200;
	std::vector<int> g(n + 1), val(n + 1), to(n + 1);
	for (int i = 1; i <= n; i++) {
		g[i] = (i - 1) / G;
	}
	for (int i = 1; i <= n; i++) {
		if (g[i] == (n - 1) / G) break;
		int x = i, j = i;
		while (g[i] == g[j]) {
			j++;
			if (a[j] - a[x] > L) {
				val[i]++;
				x = j - 1;
			}
		}
		while ((g[j] + 1) * G <= n && a[j] - a[x] < L) {
			j = (g[j] + 1) * G;
			if (j + 1 <= n && a[j] - a[x] < L) j++;
		}
		j = g[i] * G + 1;
		while (j + 1 <= n && a[j] - a[x] < L) j++;
		to[i] = j - 1;
		if (to[i] != x) val[i]++;
	}
	// for (int i = 1; i <= n; i++) {
	// 	std::cout << val[i] << ' ' << to[i] << endl;
	// }
	while (Q--) {
		int l, r;
		std::cin >> l >> r;
		if (l > r) std::swap(l, r);
		int res = 0;
		while (g[l] < g[r]) {
			res += val[l];
			l = to[l];
		}
		int x = l;
		while (l < r) {
			l++;
			if (a[l] - a[x] > L) {
				res++;
				x = l - 1;
			}
		}
		if (r != x) res++; 
		std::cout << res << endl;
	}
	return 0;
}