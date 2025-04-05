#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
#define inf 1e9
using namespace std;
void file() {
    freopen("read.in", "r", stdin);
    freopen("write.out", "w", stdout);
}
const int N = 1e7 + 10, lrz = 20101009;
inline int read() {
    int sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
bool flag[N];
int n, m, prime[N], cnt, mu[N];
long long ans, sum[N];
void init() {
    mu[1] = 1; int t = min(n, m);
    for (int i = 2; i <= t; i++) {
        if (!flag[i]) {
            prime[++cnt] = i; mu[i] = -1;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= t; j++) {
            flag[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0; break;
            }
            mu[i * prime[j]] = -mu[i];
        }
    }
    for (int i = 1; i <= t; i++) {
        sum[i] = (sum[i - 1] + i * i  % lrz * (mu[i] + lrz)) % lrz;
    }
}
long long get_sum(int x, int y) {
    return (x * (x + 1) / 2 % lrz) * (y * (y + 1) / 2 % lrz) % lrz;
}
long long query(int x, int y) {
    long long res = 0;
    for (int i = 1, j; i <= min(x, y); i = j + 1) {
        j = min(x / (x / i), y / (y / i));
        res = (res + (sum[j] - sum[i - 1] + lrz) % lrz * get_sum(x / i, y / i) % lrz) % lrz;
    }
    return res;
}
signed main() {
    n = read(); m = read(); init();
    for (int i = 1, j; i <= min(n, m); i = j + 1) {
        j = min(n / (n / i), m / (m / i));
        ans = (ans + (j - i + 1) * (i + j) / 2 % lrz * query(n / i, m / j) % lrz) % lrz;
    }
    printf("%lld", ans);
    return 0;
}