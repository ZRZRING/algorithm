#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout);
#define dbg(x) cerr<<"In Line"<<__LINE__<<" the "<<#x<<" = "<<x<<'\n';

using namespace std;

const int N = 2e6 + 10;

inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int n, m;

int main() {
	n = read();
	if (n < 4) {printf("-1"); return 0;}
	if (n == 4) {printf("(2+4)*3-1"); return 0;}
	if (n % 2 == 1) {
		printf("(4*5-3)*(2-1)");
		for (int i = 6; i <= n; i += 2) {
			printf("*(%d-%d)", i + 1, i);
		}
	} else {
		printf("4*5-(6-3)*(2-1)");
		for (int i = 7; i <= n; i += 2) {
			printf("*(%d-%d)", i + 1, i);
		}
	}
	return 0;
}