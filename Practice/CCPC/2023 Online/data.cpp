#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define rd() (rand() << 15 | rand())
#define roll(x, y) (rd() % ((x) - (y) + 1) + (x))

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	srand(time(0));
	int n = roll(5, 10); printf("%d\n", n);
	for (int i = 1; i <= n; i++) printf("%d %d\n", roll(1, 10), roll(1, 10));
	return 0;
}