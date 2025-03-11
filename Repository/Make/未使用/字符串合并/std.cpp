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

const int N = 2e5, mod = 998244353, inf = 0x3f3f3f3f;

void solve() {
	int n = read() * 2;
	std::string s, t, g;
	std::cin >> s >> t >> g;
	std::vector<int> vis_s(30), vis_t(30), vis_g(30);
	std::vector<PII> limit(30);
	for (int i = 0; i < n; i++) vis_s[s[i] - 'a']++;
	for (int i = 0; i < n; i++) vis_t[t[i] - 'a']++;
	for (int i = 0; i < n; i++) vis_g[g[i] - 'a']++;
	for (int i = 0; i < 26; i++) {
		if (vis_s[i] + vis_t[i] < vis_g[i]) {printf("No\n"); return;}
		limit[i] = {std::max(0, vis_g[i] - vis_t[i]), std::min(vis_g[i], vis_s[i])};
	}
	int low = 0, high = 0;
	for (int i = 0; i < 26; i++) {
		low += limit[i].first; high += limit[i].second;
	}
	n /= 2;
	if (n < low || n > high) printf("No\n"); else printf("Yes\n");
}

int main() {
	freopen("3.in", "r", stdin);
	freopen("3.out", "w", stdout);
	int T = read();
	while (T--) solve();
	return 0;
}