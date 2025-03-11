#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

const int N = 2e6 + 10;

int read() {
	int res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int n, m, prime[N], cnt;

bool vis[N];

int main() {
	n = read(); int ans = read();
	for (int i = 2; i <= 1000; i++) {
		if (!vis[i]) prime[++cnt] =  i;
		for (int j = 1; j <= cnt && i * prime[j] <= 1000; j++) {
			vis[i * prime[j]] = 1; if (i % prime[j] == 0) break;
		}
	}
	int x = 1; while (ans % prime[x] == 0) x++;
	ans += prime[x];
	if (x == 1) for (int i = 3; i <= n; i++) ans += 2 + (i & 1);
	else for (int i = 3; i <= n; i++) ans += 2 + !(i & 1);
	printf("%d", ans);
	return 0;
}