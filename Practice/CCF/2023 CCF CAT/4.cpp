#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 1e5 + 10;

int64 f[N][3][2], data[N][3];

void work(int64 n) {
	for (int i = 2; i <= n; i++) {
		f[i][0][0] = std::max(f[i - 1][1][1], f[i - 1][2][1]) + data[i][0];
		f[i][1][0] = f[i - 1][2][1] + data[i][1];
		f[i][1][1] = f[i - 1][0][0] + data[i][1];
		f[i][2][1] = std::max(f[i - 1][0][0], f[i - 1][1][0]) + data[i][2];
		// printf("%d %d %d %d %d %d\n", f[i][0][0], f[i][1][0], f[i][2][0], f[i][0][1], f[i][1][1], f[i][2][1]);
	}
}

int main() {
	int64 n = read();

	for (int i = 1; i <= n; i++) {
		data[i][0] = read(); data[i][1] = read(); data[i][2] = read();
	}

	int64 ans = 0;

	memset(f, 0, sizeof(f));
	f[1][0][0] = data[1][0]; work(n);
	ans = std::max(ans, f[n][1][1]);
	ans = std::max(ans, f[n][2][1]);

	memset(f, 0, sizeof(f));
	f[1][1][0] = data[1][1]; work(n);
	ans = std::max(ans, f[n][2][1]);

	memset(f, 0, sizeof(f));
	f[1][1][1] = data[1][1]; work(n);
	ans = std::max(ans, f[n][0][0]);
	
	memset(f, 0, sizeof(f));
	f[1][2][1] = data[1][2]; work(n);
	ans = std::max(ans, f[n][0][0]);
	ans = std::max(ans, f[n][1][0]);

	printf("%lld", ans);

	return 0;
}