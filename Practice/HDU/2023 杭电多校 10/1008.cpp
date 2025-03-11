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
		int n = read();
		std::vector<int> box(30, 0), cnt(30, 0), a((1 << n) - 1, 0);
		for (auto &x : a) x = read();
		std::sort(a.begin(), a.end());
		for (auto x : a) {
			for (int i = 29; i >= 0; i--) {
				if ((x >> i & 1) == 0) continue;
				if (!box[i]) box[i] = x; x ^= box[i]; cnt[i]++;
			}
		}
		bool flag = 0;
		int tot = 0;
		for (int i = 0; i <= 29; i++) {
			if (cnt[i]) if (cnt[i] != 1 << n - 1) flag = 1; else tot++;
		}
		if (flag) {printf("-1\n"); continue;}
		for (int i = 1; i <= n - tot; i++) printf("0 ");
		for (int i = 0; i <= 29; i++) if (box[i]) printf("%d ", box[i]);
		puts("");
	}
	return 0;
}