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
	int64 n = read();
	std::vector<int64> a;
	while (n) {
		a.push_back(n & 255); n >>= 8;
	}
	while (a.size() < 4) a.push_back(0);
	std::sort(a.begin(), a.end(), [](int a, int b) {return a > b;});
	int64 ans = 0;
	for (auto x : a) {
		ans <<= 8; ans += x;
	}
	printf("%lld\n", ans);
	return 0;
}