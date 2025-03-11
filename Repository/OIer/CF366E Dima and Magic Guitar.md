> 给你一个矩阵和一个序列，你要将序列中的每一个元素转化为矩阵上的对应数字的坐标，并使得相邻元素表示的坐标的曼哈顿距离中的最大值最大，求出这个最大值

武森的《浅谈信息学中的“0”和“1”》提到过这一套路

因为值域是9，预处理不到100组关系，复杂度瓶颈不在这里，考虑如何求出每组关系之间的最长曼哈顿距离

考虑曼哈顿距离的式子$|x_1 - x_2| + |y_1 - y_2|$，可以表示为

$$
\max
\left\{
\begin{matrix}
x_1 - x_2 + y_1 - y_2\\
-x_1 + x_2 + y_1 - y_2\\
x_1 - x_2 - y_1 + y_2\\
-x_1 + x_2 - y_1 + y_2\\
\end{matrix}
\right.
$$

发现每组x和y一定符号相反，这样我们用一个set维护每一个值的坐标集合的这4个值，对于每组关系，我们枚举该组关系中的一个元素，然后只需要用另一个元素的极值去更新答案即可

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
void file() {
    freopen("read.in", "r", stdin);
    freopen("write.out", "w", stdout);
}
const int N = 1e6 + 10, inf = 1e9;
inline int read() {
    int sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
set<int>S[N][4];
int n, m, rg, s[N], vis[1005][1005], len;
int main() {
    n = read(); m = read(); rg = read(); len = read();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x = read();
            S[x][0].insert(i + j);
            S[x][1].insert(i - j);
            S[x][2].insert(-i + j);
            S[x][3].insert(-i - j);
        }
    }
    int ta = read(), tb;
    for (int i = 2; i <= len; i++) {
        tb = read(); vis[ta][tb] = vis[tb][ta] = 1; ta = tb;
    }
    set<int>::iterator it; int ans = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (!vis[i][j]) continue;
            for (int k = 0; k <= 3; k++) {
                for (it = S[i][k].begin(); it != S[i][k].end(); it++) {
                    ans = max(ans, abs(*S[j][k].begin() - *it));
                    ans = max(ans, abs(*S[j][k].rbegin() - *it));
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}
```