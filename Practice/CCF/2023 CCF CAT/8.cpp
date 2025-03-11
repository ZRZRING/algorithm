#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 1e5;

struct DATA {
	int64 a, b;
};

int main() {
	int64 n = read(), a[n + 1], b[n + 1];
	for (int i = 1; i <= n; i++) a[i] = read(), b[i] = read();
	std::deque<DATA> q;
	int64 t = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		while (q.size() && a[i] <= q.back().a) {
			b[i] += q.back().b; t -= q.back().b; q.pop_back();
		}
		// printf("%d:%d %d\n", i, a[i], b[i]);
		q.push_back({a[i], b[i]}); t += b[i];
		while (q.size() && q.front().a < t - q.front().b + 1) {
			DATA c = q.front(); t -= c.b; q.pop_front();
		}
		// printf("%d %d\n", t, q.front().a);
		ans = std::max(ans, std::min(t, q.front().a));
	}
	printf("%lld", 1ll * ans * ans);
}