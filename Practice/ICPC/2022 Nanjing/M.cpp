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

int n, m, k, x[N], y[N];

int main() {
	n = read(); bool flag = 0; int res = 0;
	for (int i = 1; i <= n; i++) {
		x[i] = read(); y[i] = read(); x[i + n] = x[i]; y[i + n] = y[i];
	}
	for (int s = 1; s <= n; s++) {
		int ans = 0;
		for (int i = s + 1; i <= s + n - 1; i++) {
			if (flag) {
				if (x[i] - x[i - 1] >= 0 && y[i] - y[i - 1] > 0) ans++;
			}
			if (x[i] - x[i - 1] >= 0 && y[i] - y[i - 1] < 0) flag = 1;
			else if (flag && y[i] == y[i - 1]) flag = 1; else flag = 0;
		}
		// printf("%d\n", ans);
		res = max(res, ans);
	}
	printf("%d", res);
	return 0;
}