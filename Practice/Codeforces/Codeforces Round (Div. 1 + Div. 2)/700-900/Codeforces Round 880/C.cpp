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
	const int pow[8] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000};
	while (T--) {
		int A = read(), B = read(), C = read();
		int64 k = read(), cnt = 0;
		bool flag = 0;
		for (int i = pow[A]; i < pow[A + 1]; i++) {
			int l = std::max(pow[B], pow[C] - i);
			int r = std::min(pow[B + 1] - 1, pow[C + 1] - 1 - i);
			if (l > r) continue;
			cnt += r - l + 1;
			if (cnt >= k) {
				int a = i, b = r - cnt + k, c = a + b;
				printf("%d + %d = %d\n", a, b, c); flag = 1; break;
			}
		}
		if (!flag) printf("-1\n");
	}
	return 0;
}