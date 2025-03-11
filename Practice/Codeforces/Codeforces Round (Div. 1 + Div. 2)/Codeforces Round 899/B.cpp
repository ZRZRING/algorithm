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
	std::set<int> s;
	std::vector<std::vector<int> > a(n + 1);
	for (int i = 1; i <= n; i++) {
		int m = read();
		for (int j = 1; j <= m; j++) {
			int x = read();
			s.insert(x);
			a[i].push_back(x);
		}
	}
	int ans = 0;
	for (int i = 1; i <= 50; i++) {
		std::vector<int> vis(51, 0);
		for (int j = 1; j <= n; j++) {
			bool flag = 0;
			for (auto x : a[j]) {
				if (x == i) {flag = 1; break;}
			}
			if (flag) continue;
			for (auto x : a[j]) vis[x] = 1;
		}
		int sum = 0;
		for (auto x : vis) sum += x;
		if (sum == s.size()) continue;
		ans = std::max(ans, sum);
	}
	printf("%d\n", ans);
}

int main() {
	int T = read();
	while (T--) solve();
	return 0;
}