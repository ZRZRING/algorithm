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

int n, m, k, vis[N];

char ch[N];

void solve() {
	scanf("%s", ch + 1); n = strlen(ch + 1);
	for (int i = 1; i <= n; i++) vis[ch[i]]++;
	int ans = 0;
	for (int i = 'a'; i <= 'z'; i++) ans = max(ans, vis[i]);
	for (int i = 'a'; i <= 'z'; i++) vis[i] = 0;
	printf("%d\n", n - ans);
}

int main() {
	int T = read();
	while (T--) solve();
	return 0;
}