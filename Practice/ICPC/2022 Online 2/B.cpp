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

int n, m, a[N];

long long f[110][110];

int main() {
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 2; i <= n; i++) f[i][2] = 1ll * (a[i] - a[1]) * (a[i] - a[1]);
	for (int k = 3; k <= n - 2; k++) {
		for (int i = 2; i <= n; i++) {
			for (int j = 2; j < i; j++) {
				f[i][k] = max(f[i][k], f[j][k - 1] + 1ll * (a[i] - a[j]) * (a[i] - a[j]));
			}
		}
	}
	for (int i = 2; i <= n << 1; i += 2) printf("%lld\n", f[n][n - min(i, n - 2)]);
	return 0;
}