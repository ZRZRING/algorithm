#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 2e6 + 10;

int read() {
	int res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int n, ans[N], a[N];

void dfs(int x, int cnt, int now, int l, int r, int need) { // 当前数x，cnt个1，目前枚举位置now，左右边界l，r
	if (now == r + 1) {
		if (cnt == need) ans[++n] = x; return;
	}
	if (cnt < need) dfs(x + (1 << now - 1), cnt + 1, now + 1, l, r, need);
	dfs(x, cnt, now + 1, l, r, need);
}

int main() {
	int T = read();
	ans[1] = 2; ans[2] = 12; n = 2;
	for (int i = 4; i <= 30; i++) { // 最大0容量
		if (1 << i > 1e9) break; int x = 1 << i;
		for (int j = 2; j <= i + 1 >> 1; j++) { // 后缀0的数量
			x += (1 << j);
			dfs(x, 0, j + 2, j + 2, i, j - 2);
			x -= (1 << j);
		}
	}
	sort(ans + 1, ans + n + 1);
	printf("%d\n", n);
	while (T--) {
		int l = read(), r = read();
		int x = lower_bound(ans + 1, ans + n + 1, l) - ans;
		if (ans[x] <= r) printf("%d\n", ans[x]); else printf("-1\n");
	}
}