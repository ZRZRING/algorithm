#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define inf 1e9
#define int long long
using namespace std;
void file() {
    freopen("read.in", "r", stdin);
    freopen("write.out", "w", stdout);
}
const int N = 1e6 + 10;
inline int read() {
    int sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
int n, k, a[N], dp[20][N], ans;
int power(int a, int x) {
    int res = 1;
    while (x) {if (x & 1) res *= a; a *= a; x >>= 1;}
    return res;
}
signed main() {
    n = read(); k = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read(); dp[i][1 << i - 1] = 1;
    }
    for (int i = 1; i < pow(2, n); i++) {
        for (int x = 1; x <= n; x++) {
            if (i & (1 << x - 1)) {
                int j = i - (1 << x - 1);
                if (j != 0) {
                    for (int y = 1; y <= n; y++) {
                        if (j & (1 << y - 1) && abs(a[x] - a[y]) > k) dp[x][i] += dp[y][j];
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ans += dp[i][(1 << n) - 1];
    }
    printf("%lld", ans);
    return 0;
}