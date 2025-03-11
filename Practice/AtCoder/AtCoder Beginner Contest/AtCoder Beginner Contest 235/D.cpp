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

const int N = 1e6 + 10, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	int a = read(), n = read(), ans[N];
	memset(ans, 0, sizeof(ans));
	std::queue<int> q; q.push(1);
	ans[1] = 1;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		if (1ll * x * a < N && !ans[x * a]) q.push(x * a), ans[x * a] = ans[x] + 1;
		if (x % 10 == 0) continue;
		int t1 = x % 10, t2 = x, t3 = 1;
		while (t2) {t2 /= 10; t3 *= 10;} t3 /= 10;
		int y = x / 10 + t1 * t3;
		if (y < N && !ans[y]) q.push(y), ans[y] = ans[x] + 1;
	}
	printf("%d\n", ans[n] - 1);
	return 0;
}