#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>

#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout);
#define dbg(x) cerr<<"In Line"<<__LINE__<<" the "<<#x<<" = "<<x<<'\n';
#define abs(x) ((x) < 0 ? -(x) : (x))

using namespace std;

const int N = 2e6 + 10;

inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

char ch[N][10];

int n, m, a[N];

map<char, int>mp;

int main() {
	freopen("sub3-1.in", "r", stdin);
	freopen("sub3-1.out", "w", stdout);
	int T = read();
	while (T--) {
		n = read(); int k = read(); bool f = 0;
		for (int i = 0; i < k; i++) {
			scanf("%s", ch[i]);
			if (ch[i][0] != 'E' && ch[i][0] != 'P' && ch[i][0] != 'M') a[i] = read(); else a[i] = 1;
		}
		for (int i = 0; i < k; i++) {
			if (ch[i][0] == 'P') {printf("%d\n", i % n + 1); f = 1; break;} // 猪
			if (i - n >= 0) { // 消除上一轮影响
				if (ch[i - n][0] == 'S') { // 草莓对于象
					mp['S'] -= a[i - n];
					if (!mp['S'] && mp['E'] && (ch[i][0] != 'S' || a[i] == 0)) {
						printf("%d\n", i % n + 1); f = 1; break;
					}
				} else
				if (ch[i - n][0] == 'L') { // 柠檬对于猴子
					mp['L'] -= a[i - n];
					if (!mp['L'] && mp['M'] && (ch[i][0] != 'L' || a[i] == 0)) {
						printf("%d\n", i % n + 1); f = 1; break;
					}
				} else mp[ch[i - n][0]] -= a[i - n];
			}
			if (ch[i][0] == 'E') { // 象对于草莓
				if (mp['S'] == 0) {printf("%d\n", i % n + 1); f = 1; break;} mp[ch[i][0]] += a[i];
			} else
			if (ch[i][0] == 'M') { // 猴子对于柠檬
				if (mp['L'] == 0) {printf("%d\n", i % n + 1); f = 1; break;} mp[ch[i][0]] += a[i];
			} else mp[ch[i][0]] += a[i]; // 水果
			if (ch[i][0] != 'E' && ch[i][0] != 'M' && mp[ch[i][0]] == 5) {
				printf("%d\n", i % n + 1); f = 1; break;
			}
			if (ch[i - n][0] != 'E' && ch[i - n][0] != 'M' && mp[ch[i - n][0]] == 5) {
				printf("%d\n", i % n + 1); f = 1; break;
			}
			// map<char,int>::iterator it;
			// for (it = mp.begin(); it != mp.end(); it++) {
			// 	printf("%c %d\n", it->first, it->second);
			// }
			// printf("\n");
		}
		if (!f) printf("-1\n"); mp.clear();
	}
	return 0;
}