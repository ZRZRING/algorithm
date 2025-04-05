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
int n, m, a[3], b[3], ans;
void get(int &a, int &b, int t) {
    int mi = min(a, b); ans += mi * t; a -= mi; b -= mi;
}
int main() {
    int T = read();
    while (T--) {
        ans = 0;
        for (int i = 0; i <= 2; i++) a[i] = read();
        for (int i = 0; i <= 2; i++) b[i] = read();
        get(a[2], b[1], 2); get(a[2], b[2], 0); get(a[0], b[2], 0);
        get(a[1], b[0], 0); get(a[1], b[1], 0); get(a[1], b[2], -2);
        printf("%d\n", ans);
    }
    return 0;
}