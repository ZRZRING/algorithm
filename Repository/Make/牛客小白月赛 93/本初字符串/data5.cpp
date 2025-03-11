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
    printf("10\n");
    n = 20000;
    for (int i = 0; i < n; i++) {
		putchar(i % 26 + 'a');
	}
    puts("");
    n = 19992;
    for (int i = 0; i < n; i++) {
		putchar(i % 26 + 'a');
	}
    puts("");
    n = 19998;
    for (int i = 0; i < n / 3; i++) {
		printf("abc");
	}
    puts("");
    n = 20000;
    for (int i = 0; i < n; i++) {
		putchar(roll(0, 25) + 'a');
	}
    puts("");
    for (int i = 1; i <= 3; i++) {
        m = roll(2, 250);
        n = roll(19000, 20000);
        n = n / m * m;
        memset(ans, '\0', sizeof(ans));
        memset(qry, '\0', sizeof(qry));
        for (int i = 1; i <= m; i++) {
			ans[i] = roll(0, 25) + 'a';
		}
        for (int i = 1; i <= n; i++) {
			t[i] = i;
		}
        random_shuffle(t + 1, t + n + 1);
        for (int i = 1; i <= n / m; i++) {
            for (int j = 1; j <= m; j++) {
                qry[(i - 1) * m + j] = ans[j];
            }
        }
        for (int i = 1; i <= n / 2; i++) {
			qry[t[i]] = roll(0, 25) + 'a';
		}
        puts(qry + 1);
    }
    for (int i = 1; i <= 3; i++) {
        m = roll(20, 500);
        n = roll(19000, 20000);
        n = n / m * m;
        memset(ans, '\0', sizeof(ans));
        memset(qry, '\0', sizeof(qry));
        for (int i = 1; i <= m; i++) {
			ans[i] = roll(0, 25) + 'a';
		}
        for (int i = 1; i <= n; i++) {
			t[i] = i;
		}
        random_shuffle(t + 1, t + n + 1);
        for (int i = 1; i <= n / m; i++) {
            for (int j = 1; j <= m; j++) {
                qry[(i - 1) * m + j] = ans[j];
            }
        }
        for (int i = 1; i <= n / 2; i++) {
			qry[t[i]] = roll(0, 25) + 'a';
		}
        puts(qry + 1);
    }
    return 0;
}