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
int n, m, fail[N];
char a[N], b[N];
int main() {
	scanf("%s%s", a + 1, b + 1);
	int lena = strlen(a + 1), lenb = strlen(b + 1);
	for (int i = 2, j = 0; i <= lenb; i++) {
		while (j && b[i] != b[j + 1]) j = fail[j];
		if (b[i] == b[j + 1]) j++; fail[i] = j;
	}
	for (int i = 1, j = 0; i <= lena; i++) {
		while (j && a[i] != b[j + 1]) j = fail[j];
		if (a[i] == b[j + 1]) j++; if (j == lenb) printf("%d\n", i - lenb + 1), j = fail[j];
	}
	for (int i = 1; i <= lenb; i++) {
		printf("%d ", fail[i]);
	}
	return 0;
}