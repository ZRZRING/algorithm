#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define p(dir) putchar(dir ? 'D' : 'R');
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
int n, m, a[1001][1001][2], dp[1001][1001][2];
void print(int x, int y, int k, int dir) {
    if (x == 1 && y == 1) {p(dir); return;}
    if (x == 1) {print(x, y - 1, k, 0); p(dir); return;}
    if (y == 1) {print(x - 1, y, k, 1); p(dir); return;}
    if (dp[x][y][k] == dp[x - 1][y][k] + a[x][y][k]) {
        print(x - 1, y, k, 1); if (dir == -1) return; p(dir);   
    } else {
        print(x, y - 1, k, 0); if (dir == -1) return; p(dir);
    }
}
int main() {
    n = read(); int flag[2] = {0, 0}, zi = 0, zj = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x = read(); if (!x) {flag[0] = 1; zi = i; zj = j; a[i][j][0] = a[i][j][1] = 1; continue;}
            while (x % 2 == 0) ++a[i][j][0], x /= 2; while (x % 5 == 0) ++a[i][j][1], x /= 5;
        }
    }
    memset(dp, 0x3f, sizeof(dp)); dp[1][1][0] = dp[1][1][1] = 0;
    for (int k = 0; k <= 1; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i - 1) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                if (j - 1) dp[i][j][k] = min(dp[i][j][k], dp[i][j - 1][k]);
                dp[i][j][k] += a[i][j][k];
            }
        }
    }
    if (min(dp[n][n][0], dp[n][n][1]) > 1 && flag[0]) {
        puts("1\n");
        for (int i = 1; i < zi; i++) printf("D");
        for (int i = 1; i < zj; i++) printf("R");
        for (int i = zi; i < n; i++) printf("D");
        for (int i = zj; i < n; i++) printf("R");
        return 0;
    }
    if (dp[n][n][0] < dp[n][n][1]) printf("%d\n", dp[n][n][0]), print(n, n, 0, -1);
    else printf("%d\n", dp[n][n][1]), print(n, n, 1, -1);
    return 0;
}