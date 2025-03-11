#include <bits/stdc++.h>

#define int64 long long

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5 + 10;

int b[N];

bool cmp(int x, int y) {
	return b[x] < b[y];
}

int main() {
	int T = read();
	while (T--) {
		int n = read(), a[n + 1];
		for (int i = 1; i <= n; i++) a[i] = read() + read() * 2;
		for (int i = 1; i <= n; i++) b[i] = read();
		std::sort(a + 1, a + n + 1, cmp);
		int pre[n + 2][4] = {0}, suf[n + 2][4] = {0};
		for (int i = 1; i <= n; i++) {
			for (int p = 0; p <= 3; p++) pre[p][i] = pre[p][i - 1] + (a[i] == p);
		}
		for (int i = n; i >= 1; i--) {
			for (int p = 0; p <= 3; p++) suf[p][i] = suf[p][i + 1] + (a[i] == p);
		}
		int ans = 0, now = 0;
		for (int i = 1; i < n; i += 100) {/
			now = std::max(now, pre[1][i] - pre[0][i]);
			ans = std::max(ans, now + pre[0][i] + suf[2][i + 1]);
		}
		now = 0;
		for (int i = 1; i < n; i++) {
			now = std::max(now, pre[1][i] - pre[3][i]);
			ans = std::max(ans, now + pre[3][i] + suf[2][i + 1]);
		}
		printf("%d\n", ans);
	}
}