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

bool cmp(int a, int b) {return a > b;}

int main() {
	int n = read(), m = read(), cnt[3];
	int64 a[3][n + 1];
	init_0(cnt); init_0(a);
	for (int i = 1; i <= n; i++) {
		int opt = read(), val = read();
		a[opt][++cnt[opt]] = val;
	}
	for (int i = 0; i <= 2; i++)  {
		std::sort(a[i] + 1, a[i] + cnt[i] + 1, cmp);
		for (int j = 1; j <= cnt[i]; j++) a[i][j] += a[i][j - 1];
	}
	int ans = a[]
	for (int i = 0; i <= cnt[2]; i++) {
		
	}
	printf("%lld\n", ans);
	return 0;
}