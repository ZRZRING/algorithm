#include <bits/stdc++.h>

#define int64 long long
#define PII std::pair<int, int>
#define endl '\n'

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int ans = 0, p[5];
	for (p[1] = 0; p[1] < 62; p[1]++) {
		for (p[2] = 0; p[2] < 62; p[2]++) {
			for (p[3] = 0; p[3] < 62; p[3]++) {
				for (p[4] = 0; p[4] < 62; p[4]++) {
					if (p[1] == p[2] || p[2] == p[3] || p[3] == p[4]) continue;
					int c1 = 0, c2 = 0, c3 = 0;
					for (int i = 1; i <= 4; i++) {
						if (p[i] >= 0 && p[i] < 10) c1++;
						if (p[i] >= 10 && p[i] < 36) c2++;
						if (p[i] >= 36 && p[i] < 62) c3++;
					}
					if (!c1 || !c2 || !c3) continue;
					ans++;
				}
			}
		} 
	}
	printf("%d\n", ans);
	return 0;
}