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
	int n = read(), x[n + 1], y[n + 1], z[n + 1];
	for (int i = 1; i <= n; i++) {
		x[i] = read(); y[i] = read(); z[i] = read();
	}
	int64 ans = 1e15, resX = 0, resY = 0, resZ = 0;
	std::sort(x + 1, x + n + 1);
	std::sort(y + 1, y + n + 1);
	std::sort(z + 1, z + n + 1);
	int mid = (n + 1) / 2, midX = x[mid], midY = y[mid], midZ = z[mid];
	for (int i = 1; i <= n; i++) {
		resX += abs(x[i] - midX - i + mid);
		resX += abs(y[i] - midY);
		resX += abs(z[i] - midZ);
	}
	for (int i = 1; i <= n; i++) {
		resY += abs(x[i] - midX);
		resY += abs(y[i] - midY - i + mid);
		resY += abs(z[i] - midZ);
	}
	for (int i = 1; i <= n; i++) {
		resZ += abs(x[i] - midX);
		resZ += abs(y[i] - midY);
		resZ += abs(z[i] - midZ - i + mid);
	}
	ans = std::min({resX, resY, resZ});
	printf("%lld\n", ans);
}