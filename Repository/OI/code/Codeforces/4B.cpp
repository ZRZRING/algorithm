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

const int N = 1e6 + 10, M = 2e6 + 10, inf = 1e9;

inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

int n, m, sum, l[N], r[N], mi, mx, res[N];

int main() {
    n = read(); sum = read();
    for (int i = 1; i <= n; i++) {
        l[i] = read(); r[i] = read(); mi += l[i]; mx += r[i];
    }
    if (mi > sum || mx < sum) {printf("NO"); return 0;} printf("YES\n");
    for (int i = 1; i <= n; i++) {
        sum -= l[i]; res[i] = l[i];
    }
    for (int i = 1; i <= n; i++) {
        if (!sum) break; res[i] += min(sum, r[i] - l[i]); sum -= min(sum, r[i] - l[i]);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}