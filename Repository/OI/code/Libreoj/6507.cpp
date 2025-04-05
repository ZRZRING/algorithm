#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define ls x << 1
#define rs x << 1 | 1
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
struct TREE {
    int mi, pos; //val pos
    TREE operator | (const TREE &a) const {return (TREE){min(mi, a.mi), pos & a.pos & ~(mi ^ a.mi)};}
    TREE operator + (const TREE &a) const {return (TREE){pos | a.pos, mi & (~a.pos | a.mi) | a.pos & a.mi};}
} t[N], tag[N];
int n, m, a[N];
void pushup(int x) {t[x] = t[ls] | t[rs];}
void build(int x, int l, int r) {
    if (l == r) {t[x] = (TREE){a[l], -1}; return;}
    int mid = l + r >> 1;
    build(ls, l, mid); build(rs, mid + 1, r);
    pushup(x);
}
void modify1(int x, int l, int r, int ln, int rn, int t) {

}
void modify2(int x, int l, int r, int ln, int rn, int t) {

}
int query(int x, int l, int r, int ln, int rn) {

}
int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int opt = read(), l = read(), r = read();
        if (opt == 1) {
            int x = read(); modify1(1, 1, n, l, r, x);
        }
        if (opt == 2) {
            int x = read(); modify2(1, 1, n, l, r, x);
        }
        if (opt == 3) {
            printf("%d\n", query(1, 1, n, l, r));
        }
    }
    return 0;
}