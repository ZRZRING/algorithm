#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
void file() {
    freopen("read.in", "r", stdin);
    freopen("write.out", "w", stdout);
}
const int N = 5e2;
inline int read() {
    int sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
int n, m;
int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            a[i][j] = read();
        }
    }
    for (int i = 1; i <= n; i++) {
        
    }
    return 0;
}