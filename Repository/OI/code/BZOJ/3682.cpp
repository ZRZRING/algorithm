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
int n, m, len, type, s = 200, ch[N], a[N];
char ch1[N], ch2[2];
int main() {
    n = read(); m = read(); len = read(); type = read();
    scanf("%s", ch1); for (int i = 0; i < len; i++) ch[i + 1] = ch1[i] - 'a';
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= m; i++) {
        scanf("%s", ch2);
        if (ch2[0] == 'I') {
            
        }
        if (ch2[0] == 'C') {

        }
        if (ch2[0] == 'Q') {

        }
    }
    return 0;
}