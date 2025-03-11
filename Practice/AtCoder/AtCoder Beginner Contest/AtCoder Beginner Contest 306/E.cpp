#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

std::priority_queue<int, std::vector<int>, std::greater<int> > a;

std::priority_queue<int> b;

std::map<int, int> del;

int main() {
	int n = read(), k = read(), Q = read(), dat[n + 1] = {0};
	int64 sum = 0;
	for (int i = 1; i <= k; i++) a.push(0);
	for (int i = k + 1; i <= n; i++) b.push(0);
	for (int q = 1; q <= Q; q++) {
		int x = read(), y = read(); del[dat[x]]++;
		while (del.find(a.top()) != del.end() && del[a.top()]) del[a.top()]--, a.pop();
		while (del.find(b.top()) != del.end() && del[b.top()]) del[b.top()]--, b.pop();
		if (dat[x] >= a.top()) {
			sum -= dat[x];
			if (y >= a.top()) a.push(y), sum += y;
			else a.push(b.top()), sum += b.top(), b.pop(), b.push(y);
		} else {
			if (y <= b.top()) b.push(y);
			else b.push(a.top()), sum -= a.top(), a.pop(), a.push(y), sum += y;
		}
		dat[x] = y;
		printf("%lld\n", sum);
	}
	return 0;
}