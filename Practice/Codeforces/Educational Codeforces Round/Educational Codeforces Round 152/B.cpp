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

int main() {
	int T = read();
	while (T--) {
		int n = read(), k = read();
		PII a[n + 1];
		for (int i = 1; i <= n; i++) {
			a[i] = {read() % k, i}; if (!a[i].first) a[i].first = k;
		}
		std::sort(a + 1, a + n + 1, [](PII x, PII y){
			return x.first == y.first ? x.second < y.second : x.first > y.first;
		});
		for (int i = 1; i <= n; i++) printf("%d ", a[i].second);
		puts("");
	}
	return 0;
}