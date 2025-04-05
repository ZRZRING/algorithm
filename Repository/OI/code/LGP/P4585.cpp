#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
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
int n, m, T;
namespace TRIE {
    vector <int> tr[N];

    void add(int x, int t, int T) {

    }
}
namespace SEG {
    #define ls x << 1
    #define rs x << 1 | 1
    void pushup(int x) {
        using namespace TRIE; tr[x] = merge(tr[ls], tr[rs]);
    }
    void modify(int x, int l, int r, int pos, int t) {
        if (l == r) {TRIE::add(pos, t, T); return;}
        int mid = l + r >> 1;
        if (mid >= pos) modify(ls, l, mid, pos, t);
        else modify(rs, mid + 1, r, pos, t);
        pushup(x);
    }
}
int query(int l, int r, int t, int d) {

}
int main() {
    n = read(); m = read(); int x, t, l, r, d;
    for (int i = 1; i <= m; i++) {
        int opt = read();
        if (opt == 0) {T++; x = read(); t = read(); SEG::modify(1, 1, n, x, t);}
        if (opt == 1) {l = read(); r = read(); t = read(); d = read(); printf("%d\n", SEG::query(l, r, t, d);}
    }
    return 0;
}