> 给定所有队伍的初始rating和在最后一小时的rating变化，最后一小时前封榜，一小时后把所有队伍依次解冻，第$i$支队伍解冻前的排名为$x_i$，解冻后的排名为$y_i$，贡献为$|x_i - y_i|$，求一个解冻顺序使得贡献和最大

考虑对于任意两个队伍，不管其他队伍的影响，他们在名次变化上的贡献的最大值是可以直接求出来的

而且容易确定，最终的结果为每两个队伍的贡献的和，而且不存在冲突关系（因为初始位置和终止位置是固定的）

```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
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
struct node {
	int dat, add, id;
	bool operator < (const node a) const {return dat == a.dat ? id < a.id : dat > a.dat;}
} a[N];
int n, m;
bool cmp(node a, node b) {return a.dat > b.dat;}
void swap(node &a, node &b) {node c = a; a = b; b = c;}
int cal(node fa, node fb) {
	int res = 0; if (fb < fa) swap(fa, fb);
	node sa = fa, sb = fb; sa.dat += sa.add; sb.dat += sb.add;
    if (sb < sa) return 1;
    if (fb < sa && sa < sb) return 2;
    if (sb < fa && sa < sb) return 2;
    return 0;
}
int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
    	a[i].dat = read(); a[i].add = read(); a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp); int ans = 0;
    for (int i = 1; i <= n; i++) {
    	for (int j = i + 1; j <= n; j++) {
    		ans += cal(a[i], a[j]);
    	}
    }
    printf("%d", ans);
    return 0;
}
```