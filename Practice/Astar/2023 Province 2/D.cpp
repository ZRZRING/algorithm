#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int64 p = read(), q = read(), n1 = read(), n2 = read(), n3 = read();
	if (p * n3 < q) {printf("-1\n"); return 0;}
	int min = -1, max = -1;
	for (int i = 0; i * n3 <= q; i++) {
		if ((p - i) * n1 > q - i * n3) break;
		if ((p - i) * n2 < q - i * n3) continue;
		if (n1 == n2) {
			if ((q - i * n3) % n1 == 0 && (q - i * n3) / n1 == p - i) {
				if (min == -1) min = i; max = i;
			}
		} else {
			if (((p - i) * n2 - q + i * n3) % (n2 - n1) == 0) {
				if (min == -1) min = i; max = i;
			}
		}
	}
	if (min == -1) printf("-1"); else printf("%d %d\n", min, max);
}