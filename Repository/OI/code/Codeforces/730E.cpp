
// Problem: E. Award Ceremony
// Contest: Codeforces - 2016-2017 ACM-ICPC, NEERC, Southern Subregional Contest (Online Mirror, ACM-ICPC Rules, Teams Preferred)
// URL: http://codeforces.com/problemset/problem/730/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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