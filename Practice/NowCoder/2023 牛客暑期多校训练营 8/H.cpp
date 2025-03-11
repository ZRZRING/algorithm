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
	int n = read();
	std::vector<int> a(n + 1, 0);
	std::vector<int> vis(n + 1, 0), ans;
	for (int i = 1; i <= n; i++) a[i] = read();
	int ans = 0;
	for (int r = 1; r <= n; r++) {
		if (a[r] == 1) {
			ans.push_back(r); continue;
		}
		
	}
	printf("%d\n", ans);
	return 0;
}