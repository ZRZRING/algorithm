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
int n, m, t[N], odd, f, d;
int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        int x = read(); t[x]++;
        if (t[x] % 4 == 0) f++; if (t[x] % 4 == 3) f--;
        if (t[x] % 2 == 0) d++; if (t[x] % 2 == 1) d--;
    } 
    m = read();
    for (int i = 1; i <= n; i++) {
        char ch[2]; scanf("%s", ch); int x = read();
        if (ch[0] == '+') {
            
        } else {
            
        }
    }
    return 0;
}