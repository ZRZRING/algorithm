#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int n = read(), a[n], b[n];
	for (int i = 0; i < n; i++) a[i] = read(), b[i] = read();
	std::vector<int> ans(n + 1, 1e9);
	for (int i = 1; i < 1 << n; i++) {
		int cnt = 0, sum = 0, max = 0;
		for (int j = 0; j < n; j++) {
			if (i >> j & 1) sum += a[j], max = std::max(max, b[j]), cnt++;
		}
		ans[cnt] = std::min(ans[cnt], sum + max);
	}
	for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
	return 0;
}