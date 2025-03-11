#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <functional>

int read() {
	int res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

std::vector<int> room;

bool cmp(int a, int b) {return a > b;}

int main() {
	int n = read(), m = read(), tot = 0, val[n + 1];
	for (int i = 1; i <= n; i++) {
		std::string name; std::cin >> name >> val[i];
		std::cout << name << ' ' << (val[i] + m - 1) / m << '\n';
		tot += val[i] / m; val[i] %= m;
	}
	std::sort(val + 1, val + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		if (!val[i]) break;
		bool flag = 0; int T = room.size();
		for (int j = 0; j < T; j++) {
			if (room[j] >= val[i]) {
				room[j] -= val[i]; flag = 1; break;
			}
		}
		if (!flag) room.push_back(m - val[i]);
	}
	printf("%d", tot + room.size());
}