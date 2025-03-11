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

const int64 mod = 998244353;

void solve() {
	int n = read();
	std::vector<int> vis(n, 0);
	for (int i = 1; i <= n; i++) {
		int x = read();
		if (x >= n) continue; vis[x]++;
	}
	if (!vis[0]) {
		printf("0\n"); return;
	}
	for (int i = 1; i < n; i++) {
		if (!vis[i]) {vis.resize(i); break;}
	}
	n = vis.size();
	std::vector<int64> f(n + 1, 1e18);
	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			f[i] = std::min(f[i], f[j] + vis[j] * i);
		}
	}
	printf("%lld\n", f[n] - n);
}

int main() {
	int T = read();
	while (T--) solve();
	return 0;
}