// 网络流转对偶图+最短路
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
int n, m;
void init() {
    int N1 = read() - 1, M1 = read() - 1, t, sq = N1 * M2; S = sq * 2 + 1;
    for (int i = 1; i <= M1; i++) {
        t = read(); ins(S, i, t);
    }
    for (int i = 1; i <= N1; i++) for (int j = 1; j <= M1; j++) {
        t = read(); ins(i * M1 + j, sq + i * M1 + j, t);
    }
    for (int i = 1; i <= M1; i++) {
        t = read(); ins(S, )
    }
    for (int i = 0; i < N1; i++) {
        t = read(); ins(S, i * M1 + 1, t);
        for (int j = 1; j <= M1; j++) {
            t = read(); ins((i - 1) * 2 + 1) * M1 + j, i * 2 * M1 + j, t);
        }
    }
    for (int i = 1; i <= N1; i++) {
        t = read(); add(S, )
    }
}
int main() {
    init();
    return 0;
}