#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

struct DATA {
	int a, b;
	friend bool operator < (const DATA a, const DATA b) {
		return a.a < b.a;
	}
};

int main() {
	int n = read(), a[n + 1], b[n + 1];
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) b[read()] = i;
    for (int i = 1; i <= n; i++) a[i] = b[a[i]];
	std::vector<int> last;
    last.push_back(a[1]);
	for (int i = 2; i <= n; i++) {
		if (last.back() < a[i]) last.push_back(a[i]);
		else *std::lower_bound(last.begin(), last.end(), a[i]) = a[i];
	}
	printf("%d", n - last.size());
	return 0;
}