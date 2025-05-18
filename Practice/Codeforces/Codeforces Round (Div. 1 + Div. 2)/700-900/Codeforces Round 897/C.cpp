#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5, mod = 998244353, inf = 0x3f3f3f3f;

void solve() {
	int n = read();
	std::priority_queue<int, std::vector<int>, std::greater<int> > q;
	for (int i = 1; i <= n; i++) {
		q.push(read());
	}
	if (q.top()) {
		printf("0\n");
		fflush(stdout);
		int x = read();
		return;
	}
	int mex = 0;
	while (!q.empty() && q.top() == mex) {
		while (!q.empty() && q.top() == mex) q.pop(); mex++;
	}
	while (mex) {
		printf("%d\n", mex);
		fflush(stdout);
		mex = read();
	}
	printf("0\n");
	fflush(stdout);
	mex = read();
}

int main() {
	int T = read();
	while (T--) solve();
	return 0;
}