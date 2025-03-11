#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>

#define rd() (rand() << 15 | rand())
#define roll(x, y) (rd() % ((y) - (x) + 1) + (x))

using namespace std;

const int N = 1e6 + 10, M = 2e6 + 10, inf = 0x3f3f3f3f;

const long long Linf = 0x3f3f3f3f3f3f3f3f;

inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int n, m, cnt, T, t[N], b[N];

char ans[N], qry[N];

int main() {
	srand(time(0));
	int T = 10;
	std::cout << T << endl;
    n = 20000;
	while (T--) {
		for (int i = 0; i < n; i++) {
			putchar(roll(0, 25) + 'a');
		}
		puts("");
	}
	return 0;
}