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
		std::pair<int, int> a[n + 1];
		for (int i = 1; i <= n; i++) {
			a[i] = {read(), i};
		}
		std::sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++) {
			
		}
		int m = read();
		for (int i = 1; i <= m; i++) {

		}
	}
	return 0;
}