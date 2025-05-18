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
	int n = read();
	std::vector<int64> a(n + 1);
	int64 sum = 0;
	for (int i = 1; i <= n; i++) {
		a[i] = read(); sum += a[i];
	}
	if (sum % n != 0) {
		printf("No\n"); return;
	}
	sum /= n;
	std::vector<int64> cnt(40), pos(40), neg(40);
	for (int i = 1; i <= n; i++) {
		if (sum == a[i]) continue;
		int64 c = abs(sum - a[i]);
		int64 x = __builtin_ctz(c), y = (1 << x) + c;
		if (y & (y - 1)) {
			printf("No\n"); return;
		}
		y = __builtin_ctz(y);
		if (y == x + 1) {
			sum > a[i] ? pos[y]++ : neg[y]++;
		}
		sum > a[i] ? (cnt[y]++, cnt[x]--) : (cnt[x]++, cnt[y]--);
	}
	int64 t = 0;
	// for (int i = 0; i <= 30; i++) {
	// 	printf("%lld %lld %lld\n", cnt[i], pos[i], neg[i]);
	// }
	for (int i = 30; i >= 1; i--) {
		// printf("%lld %lld %lld\n", cnt[i], pos[i], neg[i]);
		if (!cnt[i]) continue;
		if (cnt[i] > 0) {
			if (pos[i] < cnt[i]) {
				printf("No\n"); return;
			}
			cnt[i - 1] += 2 * cnt[i];
			t -= cnt[i];
		} else {
			if (neg[i] < -cnt[i]) {
				printf("No\n"); return;
			}
			cnt[i - 1] += 2 * cnt[i];
			t -= cnt[i];
		}
	}
	// printf("%lld %lld\n", cnt[0], t);
	if (cnt[0] || t != 0) {
		printf("No\n"); return;
	}
	printf("Yes\n");
}

int main() {
	int T = read();
	while (T--) solve();
	return 0;
}