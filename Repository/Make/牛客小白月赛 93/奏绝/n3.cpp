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

int n, m, cnt, dat[N];

char ch[N];

int main() {
    n = read(); m = read(); scanf("%s", ch + 1);
    for (int i = 1; i <= n; i++) dat[i] = ch[i] - '0';
    for (int i = 1; i <= m; i++) {
        int l = read(), r = read(), ans = 0;
        for (int i = l; i <= r; i++) {
            for (int j = i + 1; j <= r; j++) {
                if (dat[i] ^ dat[j]) ans += j - i;
            }
        }
        int res = 0;
        printf("%d\n", ans, res);
    }
    return 0;
}