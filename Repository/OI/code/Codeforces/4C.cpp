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

const int N = 5e5 + 10, M = 2e6 + 10, inf = 1e9;

inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

int n, m, trie[N][26], cnt, tot[N];

char ch[50];

void ins(char *ch) {
    int len = strlen(ch), u = 0;
    for (int i = 0; i < len; i++) {
        int to = ch[i] - 'a';
        if (!trie[u][to]) trie[u][to] = ++cnt;
        u = trie[u][to]; 
    }
    if (!tot[u]) printf("OK\n"); else printf("%s%d\n", ch, tot[u]); tot[u]++;
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        scanf("%s", ch); ins(ch);
    }
    return 0;
}