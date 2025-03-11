#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <queue>

#define rd() (rand() << 15 | rand())
#define roll(x, y) (rd() % ((y) - (x) + 1) + (x))

using namespace std;

const int N = 1e6 + 10, M = 2e6 + 10, inf = 0x3f3f3f3f;

const long long Linf = 0x3f3f3f3f3f3f3f3f;

inline int read() {
    bool sym = 0;
    int res = 0;
    char ch = getchar();
    while (!isdigit(ch))
        sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch))
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

int n, m, cnt, T, t[N], b[N];

char ans[N], qry[N];

int main() {
    srand(time(0));
    printf("1\n");
    n = 200000;
	std::string s;
	s.resize(1000);
	for (int i = 0; i < 1000; i++) s[i] = roll(0, 25) + 'a';
    for (int i = 1; i <= n / 1000; i++) {
		std::cout << s;
	}
    puts("");
    return 0;
}