#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

struct CAT {
	int64 p, v;
};

int main() {
	int n = read();
	std::vector<CAT> a(n + 1, {0, 0});
	for (int i = 1; i <= n; i++) {
		a[i] = {read(), read()};
	}
	std::sort(a.begin() + 1, a.end(), [](CAT a, CAT b) {
		return a.p == b.p ? a.v < b.v : a.p > b.p;
	});
	CAT now = a[1];
	int ans = 1, res = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i].p != now.p && a[i].v <= now.v) {
			now = a[i]; ans = std::max(ans, res); res = 1; continue;
		}
		res++;
	}
	ans = std::max(ans, res);
	printf("%d\n", ans);
}