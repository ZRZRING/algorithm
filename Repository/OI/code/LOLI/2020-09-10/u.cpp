#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
void file() {
	freopen("u.in", "r", stdin);
	freopen("u.out", "w", stdout);
}
const int N = 1e3 + 10, inf = 1e9;
inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}
struct NODE {
	int x, y, len, t;
} a[N];
int n, m, res[N][N];
signed main() { file();
	n = read(); m = read();
	for (int i = 1; i <= m; i++) {
		a[i] = (NODE){read(), read(), read(), read()};
		for (int x = 1; x <= a[i].len; x++) {
			for (int y = 1; y <= a[i].len; y++) {
				if (y > x) break;
                res[x + a[i].x - 1][y + a[i].y - 1] += a[i].t;
			}
		}
	}
	int ans = 0;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) ans ^= res[x][y];
	}
	printf("%lld", ans);
	return 0;
}