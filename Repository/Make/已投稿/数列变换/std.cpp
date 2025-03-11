#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e6 + 10, M = 2e6 + 10, inf = 0x3f3f3f3f;

const long long Linf = 0x3f3f3f3f3f3f3f3f;

inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

int n, m, cnt, pos, neg, ans, l, r, dat[N];

int main() {
    n = read();
    for (int i = 1; i <= n; i++) dat[i] = read();
    for (int i = 1; i <= n - 1; i++) {
		dat[i] -= dat[i + 1];
		pos += (dat[i] > 0) * dat[i];
		neg += (dat[i] < 0) * -dat[i];
	}
    int ans = max(pos, neg);
	l = (dat[1] >= 0) * (dat[1] + 1);
    for (int i = 2; i <= n - 1; i++) r += (dat[i] <= 0) * (-dat[i] + 1);
	ans = min(ans, max(l, r));
    for (int i = 2; i <= n - 2; i++) {
		l += (dat[i] >= 0) * (dat[i] + 1);
		r -= (dat[i] <= 0) * (-dat[i] + 1);
		ans = min(ans, max(l, r));
	}
    printf("%d", ans);
    return 0;
}