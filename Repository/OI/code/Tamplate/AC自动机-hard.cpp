#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define inf 1e9
using namespace std;
void file() {
	freopen("read.in", "r", stdin);
	freopen("write.out", "w", stdout);
}
const int N = 1e6 + 10;
int read() {
	int res = 0, sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}
int n, son[N][30], fail[N], vis[N], num[N], cnt, ans;
char ch[500][500], txt[N];
queue<int>q;
void clear() {
	for (int i = 0; i <= cnt; i++) {
		for (int j = 0; j < 26; j++) son[i][j] = 0;
		fail[i] = 0; vis[i] = 0; num[i] = 0;
	}
}
void ins(int x) {
	int len = strlen(ch[x]), u = 0;
	for (int i = 0; i < len; i++) {
		int v = ch[x][i] - 'a';
		if (!son[u][v]) son[u][v] = ++cnt;
		u = son[u][v];
	}
	num[u] = x;
}
void build() {
	for (int i = 0; i < 26; i++) {
		if (son[0][i]) q.push(son[0][i]);
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < 26; i++) {
			int v = son[u][i];
			if (v) fail[v] = son[fail[u]][i], q.push(v);
			else son[u][i] = son[fail[u]][i];
		}
	}
}
void find() {
	int len = strlen(txt), u = 0;
	for (int i = 0; i < len; i++) {
		int v = txt[i] - 'a'; u = son[u][v];
		for (int x = u; x; x = fail[x]) {
			vis[num[x]]++;
		}
	}
}
int main() {
	n = read();
	while (n) {
		clear(); ans = 0; cnt = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%s", ch[i]); ins(i);
		}
		build(); scanf("%s", txt); find();
		for (int i = 1; i <= n; i++) {
			if (vis[i] > ans) ans = vis[i];
		}
		printf("%d\n", ans);
		for (int i = 1; i <= n; i++) {
			if (vis[i] == ans) printf("%s\n", ch[i]);
		}
		n = read();
	}
	return 0;
}
