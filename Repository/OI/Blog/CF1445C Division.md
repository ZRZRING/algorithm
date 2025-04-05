> 找到一个最大的数$x$，使得$x$是$a$的约数且$b$不是$x$的约数

记$a,b$分解质因数的可重集合分别为$A,B$，若$B$不是$A$的子集，即$b$不是$a$的约数，直接输出$a$即可

那么现在要找到$A$乘积最大的一个子集，使得$B$不是该子集的子集，最优的策略一定是补集为单一元素组成的子集，枚举补集由哪个元素组成，取乘积最小的补集即可

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e6 + 10, M = 2e6 + 10, inf = 0x3f3f3f3f;

const long long Linf = 0x3f3f3f3f3f3f3f3f;

inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

inline long long Lread() {
    bool sym = 0; long long res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

int n, m, cnt;

long long a, b, prime[N];

bool flag[N];

void init(long long N) {
    flag[1] = 0;
    for (long long i = 2; i <= N; i++) {
        if (!flag[i]) prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= N; j++) {
            flag[i * prime[j]] = 1; if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    int T = read(); init(100000);
    while (T--) {
        a = Lread(); b = Lread(); long long ans = Linf, c = a;
        if (a % b != 0) {printf("%lld\n", a); continue;}
        for (int i = 1; i <= cnt; i++) {
            if (a % prime[i] == 0) {
                long long ta = 1, tb = 1;
                while (a % prime[i] == 0) a /= prime[i], ta *= prime[i];
                while (b % prime[i] == 0) b /= prime[i], tb *= prime[i];
                if (tb == 1) continue; if (ta >= tb) ans = min(ans, ta / tb * prime[i]);
            }
        }
        if (b != 1) {
            long long ta = 1; while (a % b == 0) a /= b, ta *= b; ans = min(ans, ta);
        }
        printf("%lld\n", c / ans);
    }
    return 0;
}

```