#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int64, int64>
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
	int n = read(), k = read(), a = read(), b = read();
	std::vector<PII> node;
	node.push_back({0, 0});
	for (int i = 1; i <= n; i++) {
		node.push_back({read(), read()});
	}
	int64 mina = 1e15, minb = 1e15;
	for (int i = 1; i <= k; i++) {
		mina = std::min(mina, abs(node[a].first - node[i].first) + abs(node[a].second - node[i].second));
	}
	for (int i = 1; i <= k; i++) {
		minb = std::min(minb, abs(node[b].first - node[i].first) + abs(node[b].second - node[i].second));
	}
	int64 ans = abs(node[a].first - node[b].first) + abs(node[a].second - node[b].second);
	ans = std::min(ans, (a <= k ? 0 : mina) + (b <= k ? 0 : minb));
	printf("%lld\n", ans);
}

int main() {
	int T = read();
	while (T--) solve();
	return 0;
}