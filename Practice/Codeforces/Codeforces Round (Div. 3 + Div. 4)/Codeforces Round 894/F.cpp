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
		int64 _A = read(), _B = read();
		int n = read(), sum = 0;
		std::vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			a[i] = read(); sum += a[i];
		}
		std::bitset<(int)1e7> vis;
		vis[0] = 1;
		for (int i = 1; i <= n; i++) {
			vis |= vis << a[i];
		}
		auto check = [&](int x) -> bool {
			int64 A = x * _A, B = x * _B;
			if (A >= sum || B >= sum) return 1;
			if (A + B < sum) return 0;
			for (int i = A; i >= 0; i--) {
				if (vis[i]) {
					if (sum - i <= B) return 1; else return 0;
				}
			}
			return 0;
		};
		int l = 1, r = 1e9;
		while (l < r) {
			int mid = l + r >> 1;
			if (check(mid)) r = mid; else l = mid + 1;
		}
		printf("%d\n", r);
	}
	return 0;
}