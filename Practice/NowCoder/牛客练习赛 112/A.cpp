#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int T = read(), N = 1e6, prime[N + 1], cnt = 0;
	bool flag[N + 1];
	flag[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (!flag[i]) prime[++cnt] = i;
		for (int j = 1; j <= cnt && i * prime[j] <= N; j++) {
			flag[i * prime[j]] = 1; if (i % prime[j] == 0) break;
		}
	}
	while (T--) {
		int x = read(); bool ans = 1;
		while (x) {
			if (flag[x]) {ans = 0; break;} x /= 10;
		}
		printf(ans ? "YES\n" : "NO\n");
	}
	return 0;
}