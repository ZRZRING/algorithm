#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
void file() {
    freopen("std.in", "r", stdin);
    freopen("wa.out", "w", stdout);
}
const int N = 1e6 + 10, inf = 1e9;
inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
inline long long lread() {
    bool sym = 0; long long res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
struct NODE {
	long long p1, p2; int val;
} a[N];
NODE operator + (const NODE a, const NODE b) {
	long long ra = ~(a.p1 | a.p2), rb = ~(b.p1 | b.p2);
	return (NODE){a.p2 & b.p2 | a.p1 & rb | ra & b.p1, a.p1 & b.p1 | a.p2 & rb | ra & b.p2, a.val};
}
NODE operator - (const NODE a, const NODE b) {
	long long ra = ~(a.p1 | a.p2), rb = ~(b.p1 | b.p2);
	return (NODE){a.p2 & b.p1 | a.p1 & rb | ra & b.p2, a.p1 & b.p2 | a.p2 & rb | ra & b.p1, a.val};
}
int n, m;
long long ans;
void ins(NODE x) {
	for (int i = 60; i >= 0; i--) {
		if (x.p1 >> i & 1 | x.p2 >> i & 1) {
			if (!a[i].val) {
				ans += x.val; a[i] = x; return;
			}
			if (x.val > a[i].val) {
				ans += x.val - a[i].val; swap(a[i], x);
			}
			if ((x.p1 >> i & 1) & (a[i].p1 >> i & 1) | (x.p2 >> i & 1) & (a[i].p2 >> i & 1)) {
				x = x - a[i];
			} else {
				x = x + a[i];
			}
		}
	}
}
int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
    	long long x = lread() ^ ans; int y = read();
    	ins((NODE){x, 0, y}); printf("%lld\n", ans);
    }
    return 0;
}