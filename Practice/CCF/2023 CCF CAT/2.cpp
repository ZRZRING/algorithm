#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 1e5;

int s[N][2], val[N], cnt;

int main() {
	int n = read();
	for (int i = 1; i <= n; i++) {
		int x = read(), u = 1;
		if (!cnt) {val[++cnt] = x; continue;}
		while (s[u][x > val[u]]) u = s[u][x > val[u]];
		s[u][x > val[u]] = ++cnt; val[cnt] = x;
	}
	for (int i = 1; i <= n; i++) {
		int x = read(), u = 1, ans = 2;
		while (s[u][x > val[u]]) u = s[u][x > val[u]], ans++;
		printf("%d\n", ans);
	}
}