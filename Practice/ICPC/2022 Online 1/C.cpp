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

int n, vis[N];

int main() {
	int T = read();
	while (T--) {
		n = read(); int ans = 0;
		if (n == 1) {printf("1\n"); continue;}
		for (int i = 1; i < n; i++) {
			int x = read(), y = read(); vis[x]++; vis[y]++;
		}
		for (int i = 1; i <= n; i++) {
			if (vis[i] == 1) ans++;
		}
		for (int i = 1; i <= n; i++) vis[i] = 0;
		printf("%d\n", ans);
	}
}