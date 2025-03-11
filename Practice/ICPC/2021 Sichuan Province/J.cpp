#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int64 N = 1e9 + 1;

struct DATA {
	int64 pos, dir;
	friend bool operator < (const DATA a, const DATA b) {
		return a.pos < b.pos;
	}
};

signed main() {
	int64 n = read(); int64 a = read(), b = read();
	DATA data[n + 1];
	for (int64 i = 1; i <= n; i++) data[i].pos = read();
	for (int64 i = 1; i <= n; i++) data[i].dir = read();
	std::sort(data + 1, data + n + 1);
	int64 l[n + 1], r[n + 2];
	l[0] = 0;
	for (int64 i = 1; i <= n; i++) {
		l[i] = l[i - 1] + (data[i].dir == 0);
	}
	r[n + 1] = 0;
	for (int64 i = n; i >= 1; i--) {
		r[i] = r[i + 1] + (data[i].dir == 1);
	}
	int64 ans = std::min(a / n, b / n);
	a -= ans * n; b -= ans * n; ans *= N * 2;
	int64 res = 0;
	for (int64 i = 1; i <= n; i++) {
		if (data[i].dir == 0) {
			if (a < l[i]) res = std::max(res, data[i].pos);
			else if (b < r[1] + l[i]) res = std::max(res, data[i].pos + N);
			// else if (a < n + l[i]) res = std::max(res, data[i].pos + 2 * N);
			// else if (b < n + r[1] + l[i]) res = std::max(res, data[i].pos + 3 * N);
		} else {
			if (b < r[i]) res = std::max(res, N - data[i].pos);
			else if (a < l[n] + r[i]) res = std::max(res, N - data[i].pos + N);
			// else if (b < n + r[i]) res = std::max(res, N - data[i].pos + 2 * N);
			// else if (a < n + l[1] + r[i]) res = std::max(res, N - data[i].pos + 3 * N);
		}
	}
	printf("%lld", ans + res);
	return 0;
}