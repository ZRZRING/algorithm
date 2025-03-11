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
	int n = read(), k = read();
	bool vis[10] = {0};
	for (int i = 1; i <= k; i++) {
		vis[read()] = 1;
	}
	for (int i = n; i <= 100000; i++) {
		int x = i;
		bool flag = 0;
		while (x) {
			if (vis[x % 10]) flag = 1; x /= 10;
		}
		if (!flag) {printf("%d\n", i); return 0;}
	}
	return 0;
}