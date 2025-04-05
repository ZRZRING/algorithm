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

const int N = 5e6 + 10, M = 2e6 + 10, inf = 1e9;

inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

int n, ans, p[N], s[N], top, cnt;

char ch[N];

int main() {
    scanf("%s", ch + 1); n = strlen(ch + 1);
    for (int i = 1; i <= n; i++) {
        if (ch[i] == '(') s[++top] = i; else if (top) {p[s[top--]] = p[i] = 1;}
    }
    for (int i = 1; i <= n; i++) {
        int res = 0; while (p[i]) res++, i++; if (res > ans) ans = res, cnt = 1; else if (res == ans) cnt++;
    }
    printf("%d %d", ans, ans ? cnt : 1);
    return 0;
}