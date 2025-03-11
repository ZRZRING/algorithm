#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5 + 10, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	int n = read(), m = read(), Q = read();
	PII row[n + 1], col[m + 1];
	for (int i = 1; i <= n; i++) row[i].first = 0;
	for (int i = 1; i <= m; i++) col[i].first = 0;
	for (int i = 1; i <= Q; i++) {
		std::string opt, st;
		std::cin >> opt; int x = read(); std::cin >> st;
		if (opt[0] == 'r') row[x] = {(st[1] == 'n' ? 1 : 0), i};
		if (opt[0] == 'c') col[x] = {(st[1] == 'n' ? 1 : 0), i};
	}
	std::sort(row + 1, row + n + 1, [](PII x, PII y){
		return x.second > y.second;
	});
	std::sort(col + 1, col + m + 1, [](PII x, PII y){
		return x.second > y.second;
	});
	// for (int i = 1; i <= n; i++) printf("%d %d\n", row[i].first, row[i].second);
	// for (int i = 1; i <= m; i++) printf("%d %d\n", col[i].first, col[i].second);
	int64 ans = 0, R = m, C = n;
	for (int i = 1, j = 1; i <= n || j <= m;) {
		if (i == n + 1) {ans += col[j].first * C, j++; continue;}
		if (j == m + 1) {ans += row[i].first * R, i++; continue;}
		if (row[i].second > col[j].second) ans += row[i].first * R, C--, i++;
		else ans += col[j].first * C, R--, j++;
	}
	printf("%lld", ans);
	return 0;
}