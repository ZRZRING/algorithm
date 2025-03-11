#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

const int N = 2e6 + 10;

int read() {
	int res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

struct ANS {
	int m, n;
} ans;

int n, m, k, opt;

int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}

void solve() {
	n = read(); ans.n = ans.m = 1;
	bool flag = 0; int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int opt = read();
		if (opt == -1) {
			if (ans.n > 1) ans.n--; else if (cnt) ans.m++, ans.n++, cnt--; else flag = 1;
		}
		if (opt == 0) {
			if (ans.n > 1) ans.n--, cnt++; else ans.n++, ans.m++;
		}
		if (opt == 1) {
			ans.n++; ans.m++;
		}
		// printf("%d %d\n", ans.m, ans.n);
	}
	if (flag) {printf("-1\n"); return;}
	int d = gcd(ans.m, ans.n);
	printf("%d %d\n", ans.m / d, ans.n / d);
}

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int T = read();
	while (T--) solve();
	return 0;
}