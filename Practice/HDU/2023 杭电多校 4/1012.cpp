#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5 + 10, mod = 998244353, inf = 0x3f3f3f3f;

struct DATA {
	int64 a[2], sum;
};

int main() {
	int T = read();
	while (T--) {
		int n = read();
		DATA data[n + 1];
		for (int i = 1; i <= n; i++) {
			data[i] = {read(), read(), 0};
			data[i].sum = data[i].a[0] + data[i].a[1];
		}
		int64 ans[2] = {0};
		std::sort(data + 1, data + n + 1, [](DATA x, DATA y){return x.sum > y.sum;});
		for (int i = 1; i <= n; i++) {
			int x = i & 1 ^ 1;
			ans[x] += data[i].a[x];
		}
		printf("%lld\n", ans[0] - ans[1]);
	}
	return 0;
}