#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
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
int n, m;
int main() {
    srand(time(0)); n = 2; m = 2;
    printf("%d %d\n", n, m);
    for (int i = 1; i <= n; i++) {
        int x2 = n, y2 = rand() % n + 1;
        int x1 = 1, y1 = rand() % n + 1;
        if (x1 > x2) swap(x1, x2); if (y1 > y2) swap(y1, y2);
        printf("%d %d\n", y1, y2);
    }
    for (int i = 1; i <= m; i++) {
        int x2 = n, y2 = rand() % n + 1;
        int x1 = 1, y1 = rand() % n + 1;
        if (x1 > x2) swap(x1, x2); if (y1 > y2) swap(y1, y2);
        printf("%d %d %d\n", y1, y2, rand() % (y2 - y1 + 1) + 1);
    }
    return 0;
}