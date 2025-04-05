#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

#define lowbit(x) (x & -x)

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
    n = read(); int k = read();
    for (int i = 1; i <= n; i++) k = read();
    for (int i = 1; i <= n; i++) {
        int c = lowbit(i), res = 1;
        while (!(c & 1)) c >>= 1, res++;
        printf("%d ", res);
    }
    return 0;
}