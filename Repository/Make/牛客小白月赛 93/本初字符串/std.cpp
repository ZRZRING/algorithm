#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

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

int n, m, cnt, dat[N], vis[N][26], suf[N];

char ch[N], ans[N];

int main() {
    int T = read();
    while (T--) {
        scanf("%s", ch + 1);
        n = strlen(ch + 1);
        bool flag = 1;
        cnt = 0;
        memset(ans, '\0', sizeof(ans));
        for (int i = 1; i <= sqrt(n) + 1; i++) {
            if (n % i == 0)
                dat[++cnt] = i, dat[++cnt] = n / i;
        }
        sort(dat + 1, dat + cnt + 1);
        for (int i = 1; i <= cnt; i++) {
            int len = dat[i];
            for (int s = 1; s <= len; s++) {
                memset(vis[s], 0, sizeof(vis[s]));
                for (int i = s; i <= n; i += len) {
                    vis[s][ch[i] - 'a']++;
                    suf[s] = max(suf[s], vis[s][ch[i] - 'a']);
                }
            }
            for (int i = len - 1; i >= 1; i--) {
				suf[i] += suf[i + 1];
			}
            if (suf[1] >= (n + 1) / 2) {
                int sum = 0;
                for (int s = 1; s <= len; s++) {
                    for (int i = 0; i < 26; i++) {
                        if (vis[s][i] + sum + suf[s + 1] >= (n + 1) / 2) {
                            sum += vis[s][i];
                            ans[s] = i + 'a';
                            break;
                        }
                    }
				}
                for (int i = 1; i <= len; i++) suf[i] = 0;
                break;
            }
            for (int i = 1; i <= len; i++)
                suf[i] = 0;
        }
        puts(ans + 1);
    }
    return 0;
}