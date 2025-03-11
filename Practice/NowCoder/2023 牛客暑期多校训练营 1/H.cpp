#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int64, int64>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))
#define l first
#define r second

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	int n = read();
	std::vector<PII> data(n), S, T;
	for (int i = 0; i < n; i++) data[i].l = read();
	for (int i = 0; i < n; i++) data[i].r = read();
	int64 sum = 0;
	for (auto [l, r] : data) {
		sum += abs(l - r);
		if (l > r) S.emplace_back(r, l); else T.emplace_back(l, r);
	}
	if (S.size() == 0 || T.size() == 0) {
		printf("%lld\n", sum); return 0;
	}
	std::sort(S.begin(), S.end());
	std::sort(T.begin(), T.end());
	std::vector<int64> Smax(n, -1e9), Tmax(n, -1e9);
	Smax[0] = S[0].r; Tmax[0] = T[0].r;
	for (int i = 1; i < S.size(); i++) Smax[i] = std::max(Smax[i - 1], S[i].r);
	for (int i = 1; i < T.size(); i++) Tmax[i] = std::max(Tmax[i - 1], T[i].r);
	int64 ans = 0;
	for (int i = 0; i < S.size(); i++) {
		int x = std::upper_bound(T.begin(), T.end(), S[i]) - T.begin() - 1;
		if (x < 0) continue;
		ans = std::max(ans, std::min(Tmax[x], S[i].r) - S[i].l);
	}
	for (int i = 0; i < T.size(); i++) {
		int x = std::upper_bound(S.begin(), S.end(), T[i]) - S.begin() - 1;
		if (x < 0) continue;
		ans = std::max(ans, std::min(Smax[x], T[i].r) - T[i].l);
	}
	printf("%lld\n", sum - ans * 2);
	return 0;
}