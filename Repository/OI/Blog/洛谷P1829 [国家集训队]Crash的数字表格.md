经典莫反入门题目

题目让我们求

$$
\sum_{i = 1}^{n} \sum_{j = 1}^{n} \operatorname{lcm}(i, j)
$$

我们知道

$$
\operatorname{lcm}(i, j) \times \gcd(i, j) = i \times j
$$

化式子

$$
\begin{aligned}
\sum_{i = 1}^{n} \sum_{j = 1}^{m} \operatorname{lcm}(i, j)
&= \sum_{i = 1}^{n} \sum_{j = 1}^{m} \frac{ij}{\gcd(i, j)} \\
&= \sum_{i = 1}^{n} \sum_{j = 1}^{m} \sum_{d = 1}^{n} [\gcd(i, j) = d] \frac{ij}{d} \\
&= \sum_{d = 1}^{n} d \sum_{i = 1}^{\lfloor \frac{n}{d}\rfloor} \sum_{j = 1}^{\lfloor\frac{m}{d}\rfloor} [\gcd(i, j) = 1] ij
\end{aligned}
$$

记

$$
\begin{aligned}
\operatorname{sum}(x, y)
&= \sum_{i = 1}^{x} \sum_{j = 1}^{y} [\gcd(i, j) = 1] ij \\
&= \sum_{i = 1}^{x} \sum_{j = 1}^{y} \sum_{d|i, d|j} \mu(d) ij \\
&= \sum_{d = 1}^{n} d^2 \mu(d) \sum_{i = 1}^{\lfloor \frac{x}{d} \rfloor} \sum_{j = 1}^{\lfloor \frac{y}{d} \rfloor} ij \\
\end{aligned}
$$

$\operatorname{sum}$的前半部分可以预处理，后半部分可以直接计算

$$
\sum_{i = 1}^{n} \sum_{j = 1}^{m} ij = \frac{n(n + 1)}{2} \times \frac{m(m + 1)}{2}
$$

原式变为

$$
\sum_{d = 1}^{n} d \operatorname{sum}(\lfloor \frac{n}{d} \rfloor, \lfloor \frac{m}{d} \rfloor)
$$

显然这是一个可以数论分块的式子，于是就很好写出来了

```
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
const int N = 1e7 + 10, mod = 20101009;
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
        sum[i] = (sum[i - 1] + i * i  % mod * (mu[i] + mod)) % mod;
    }
}
long long get_sum(int x, int y) {
    return (x * (x + 1) / 2 % mod) * (y * (y + 1) / 2 % mod) % mod;
}
long long query(int x, int y) {
    long long res = 0;
    for (int i = 1, j; i <= min(x, y); i = j + 1) {
        j = min(x / (x / i), y / (y / i));
        res = (res + (sum[j] - sum[i - 1] + mod) % mod * get_sum(x / i, y / i) % mod) % mod;
    }
    return res;
}
signed main() {
    n = read(); m = read(); init();
    for (int i = 1, j; i <= min(n, m); i = j + 1) {
        j = min(n / (n / i), m / (m / i));
        ans = (ans + (j - i + 1) * (i + j) / 2 % mod * query(n / i, m / j) % mod) % mod;
    }
    printf("%lld", ans);
    return 0;
}
```