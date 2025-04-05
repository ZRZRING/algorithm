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

struct MAP {
    int l, r;
} pos[N];

int n, m;

namespace W1 {
    int cnt;

    void work() {
        for (int i = 1; i <= m; i++) {
            int l = read(), r = read(), k = read(), flag = 0;
            for (int i = 1; i <= n; i++) {
                if (pos[i].r >= l && pos[i].l <= r) k--;
                if (!k) {flag = 1; printf("%d\n", i); break;}
            }
            if (!flag) printf("-1\n");
        }
    }
}

int main() {
    n = read(); m = read(); int flag1 = 1;
    for (int i = 1; i <= n; i++) {
        pos[i] = (MAP){read(), read()};
    }
    W1::work();
    return 0;
}