#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define inf 1e9
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
int n, m, d, cnt;
int flag[N], prime[N], mu[N];
void init() {
    mu[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (!flag[i]) {
            prime[++cnt] = i; mu[i] = -1;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= N; j++) {
            flag[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0; break;
            }
            mu[i * prime[j]] = -mu[i];
        }
    }
    for (int i = 2; i <= N; i++) mu[i] += mu[i - 1];
}
int main() {
    int T = read(); init();
    while (T--) {
        n = read(); m = read(); d = read();
        n = n / d; m = m / d; int ans = 0;
        for (int i = 1, j; i <= min(n, m); i = j + 1) {
            j = min(n / (n / i), m / (m / i));
            ans += (mu[j] - mu[i - 1]) * (n / i) * (m / i);
        }
        printf("%d\n", ans);
    }
    return 0;
}