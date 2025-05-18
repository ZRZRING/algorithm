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
	std::vector<int64> add(n + 1), del(n + 1);
	for (int i = 1; i <= n; i++) {
		if (sum == a[i]) continue;
		int64 c = abs(sum - a[i]);
		if (sum > a[i]) {
			del[i] = 1 << __builtin_ctz(c);
			add[i] = del[i] + c;
			if (add[i] != 1 << __builtin_ctz(add[i])) {
				printf("No\n"); return;
			}
		} else {
			add[i] = 1 << __builtin_ctz(c);
			del[i] = add[i] + c;
			if (del[i] != 1 << __builtin_ctz(del[i])) {
				printf("No\n"); return;
			}
		}
	}
	// for (int i = 1; i <= n; i++) printf("%lld ", add[i]); puts("");
	// for (int i = 1; i <= n; i++) printf("%lld ", del[i]); puts("");
	std::sort(add.begin() + 1, add.end());
	reverse(add.begin() + 1, add.end());
	std::sort(del.begin() + 1, del.end());
	reverse(del.begin() + 1, del.end());
	for (int i = 1; i <= n; i++) {
		if (add[i] != del[i]) {
			printf("No\n"); return;
		}
	}
	printf("Yes\n");
}

int main() {
	int T = read();
	while (T--) solve();
	return 0;
}