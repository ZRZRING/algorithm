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

int n, m;

int main() {
    int T = read();
    while (T--) {
        n = read(); int res = 0;
        for (int i = 1; i <= n; i++) {
            res += i; if (res >= n) {printf("%d\n", i - 1 << 1); break;}
            res += i; if (res >= n) {printf("%d\n", i - 1 << 1 | 1); break;}
        }
    }
    return 0;
}