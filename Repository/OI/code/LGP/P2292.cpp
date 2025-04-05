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
struct TRIE {
    int vis[30], des;
} trie[N];
int n, m, cnt;
char ch[N];
void ins(char *ch) {
    int len = strlen(ch), x = 0;
    for (int i = 0; i < len; i++) {
        int to = ch[i] - 'a';
        if (!trie[x].vis[to]) trie[x].vis[to] = ++cnt;
        x = trie[x].vis[to];
    }
    trie[x].des = 1;
}
int query(char *ch) {
    int x = 0;
    for (int i = 0; i < 30; i++) {
        if (trie[i].)
    }
}
int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) {
        scanf("%s", ch); ins(ch);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%s", ch); printf("%d\n", query(ch));
    }
    return 0;
}