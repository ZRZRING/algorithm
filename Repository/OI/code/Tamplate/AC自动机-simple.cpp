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
const int N = 1e6 + 10;
inline int read() {
    int sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
int n, m, cnt, tot[N], son[N][30], fail[N], ans;
char ch[N];
void ins(char *ch) {
    int len = strlen(ch), u = 0;
    for (int i = 0; i < len; i++) {
        int v = ch[i] - 'a';
        if (!son[u][v]) son[u][v] = ++cnt;
        u = son[u][v];
    }
    tot[u]++;
}
void build() {
	queue<int>q;
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
	int u = 0, len = strlen(ch);
	for (int i = 0; i < len; i++) {
		int v = ch[i] - 'a'; u = son[u][v];
		for (int x = u; x && tot[x]; x = fail[x]) {
			ans += tot[x]; tot[x] = 0;
		}
	}
}
int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        scanf("%s", ch); ins(ch);
    }
    scanf("%s", ch); build(); find();
    printf("%d\n", ans);
    return 0;
}
