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

int main() {
	int T = read();
	while (T--) {
		int n = read(), k = read() - 1, a[n + 1], vis[n + 1] = {0};
		for (int i = 0; i < n; i++) {
			a[i] = read(); vis[a[i]]++;
		}
		// if (n == 1) {printf("%d\n", k % 2 == 0 ? a[1] : !a[1]); continue;}
		std::priority_queue<int, std::vector<int>, std::greater<int> > q;
		for (int i = 0; i <= n; i++) {
			if (!vis[i]) q.push(i);
		}
		for (int i = 0; i < n; i++) {
			int t = a[i]; vis[t]--;
			a[i] = q.top(); q.pop();
			if (!vis[t]) q.push(t);
		}
		a[n] = q.top();
		// for (int i = 0; i <= n; i++) printf("%d ", a[i]); puts("");
		int s = (n - k % (n + 1) + 1) % (n + 1);
		for (int i = s; i != (s + n) % (n + 1); i = (i + 1) % (n + 1)) {
			printf("%d ", a[i]);
		}
		puts("");
	}
	return 0;
}