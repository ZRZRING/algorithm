#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int n = read();
	int64 dp[2][2] = {0};
	for (int i = 1; i <= n; i++) {
		int opt = read(), val = read();
		if (opt == 0) {
			dp[i & 1][0] = std::max(dp[i & 1 ^ 1][0] + std::max(0, val), dp[i & 1 ^ 1][1] + val);
			dp[i & 1][1] = dp[i & 1 ^ 1][1];
		}
		if (opt == 1) {
			dp[i & 1][0] = dp[i & 1 ^ 1][0];
			dp[i & 1][1] = std::max(dp[i & 1 ^ 1][0] + val, dp[i & 1 ^ 1][1]);
		}
	}
	printf("%lld", std::max(dp[n & 1][0], dp[n & 1][1]));
	return 0;
}