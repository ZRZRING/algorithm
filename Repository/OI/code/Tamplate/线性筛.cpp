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
const int N = 1e8 + 10;
inline int read() {
	int sym = 0, res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}
bool flag[N];
int n, m, prime[N], cnt;
int main() {
	n = read(); m = read();
	for (int i = 2; i <= n; i++) {
		if (!flag[i]) prime[++cnt] = i;
		for (int j = 1; j <= cnt && i * prime[j] <= n; j++) {
			flag[i * prime[j]] = 1; if (i % prime[j] == 0) break;
		}
	}
	for (int i = 1, x; i <= m; i++) {
		x = read(); printf("%d\n", prime[x]);
	}
	return 0;
}