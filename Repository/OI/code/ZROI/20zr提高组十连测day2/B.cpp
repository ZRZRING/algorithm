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
const int N = 1e6 + 10, inf = 1e9;
inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
struct NODE {
    int c[11], len;
} str[N], cpy[N];
int n, m, t1[30], t2[30];
char ch[11];
bool cmp(NODE a, NODE b) {
    for (int i = 1; i <= a.len; i++) t1[i] = a.c[i];
    for (int i = 1; i <= b.len; i++) t1[i + a.len] = b.c[i];
    for (int i = 1; i <= b.len; i++) t2[i] = b.c[i];
    for (int i = 1; i <= a.len; i++) t2[i + b.len] = a.c[i];
    for (int i = 1; i <= a.len + b.len; i++) {
        if (t1[i] != t2[i]) return t1[i] < t2[i];
    }
    return 0;
}
int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        scanf("%s", ch + 1); str[i].len = strlen(ch + 1);
        for (int j = 1; j <= str[i].len; j++) str[i].c[j] = ch[j] - 'a';
    }
    sort(str + 1, str + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= str[i].len; j++) putchar(str[i].c[j] + 'a'); 
    }
    return 0;
}
