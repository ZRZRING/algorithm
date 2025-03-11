#include <bits/stdc++.h>

#define int64 long long
#define PII std::pair<int, int>

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int n = read(), T = read(), a[n + 1], ans = 2;
	for (int i = 1; i <= n; i++) {
		a[i] = read(); ans = std::max(ans, (a[i] + T - 1) / T);
	}
	printf("%d", ans);
	return 0;
}