#include <bits/stdc++.h>
 
#define int64 long long
 
inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}
 
int main() {
	int T = read();
	while (T--) {
		int n = read(), m = read(); int64 a = 0, b = 0;
		for (int i = 1; i <= n; i++) a += read();
		for (int i = 1; i <= m; i++) b += read();
		if (a < b) printf("Tenzing\n");
		if (a > b) printf("Tsondu\n");
		if (a == b) printf("Draw\n");
	}
	return 0;
}