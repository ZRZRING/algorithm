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
const int N = 1e6 + 10, inf = 1e9, dsq = 1e9 + 7;
inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
int n, m;
long long mul[N], pre[N];
int main() {
    n = read(); q = read(); m = read(); mul[0] = 1ll;
    for (int i = 1; i <= n; i++) mul[i] = (mul[i - 1] << 1) % dsq;
    for (int i = 1; i <= n; i++) pre[i] = (pre[i - 1] + mul[i]) % dsq;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = 
        }
    }
    return 0;
}