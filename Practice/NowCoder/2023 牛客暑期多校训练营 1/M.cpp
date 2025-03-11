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

int exgcd(int a, int b, int64 &x, int64 &y) {
	if (!b) {x = 1; y = 0; return a;}
	exgcd(b, a % b, y, x); y -= x * (a / b);
}

int main() {
	int T = read();
	while (T--) {
		int64 a = read(), b = read(), c = read();
		int64 x, y, d = exgcd(a, b, x, y);
		a /= d; b /= d;
		
	}
	return 0;
}