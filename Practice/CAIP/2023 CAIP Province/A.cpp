#include <bits/stdc++.h>

#define int64 long long

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int n = read(), a[2][4] = {0};
	for (int i = 1; i <= n; i++) {
		int x = read(), t = read(); a[x][t]++;
	}
	printf("%d %d %d\n", a[0][1], a[0][2], a[0][3]);
	printf("%d %d %d\n", a[1][1], a[1][2], a[1][3]);
	if (a[0][1] > a[1][1]) {
		printf("The first win!"); return 0;
	} 
	if (a[0][1] < a[1][1]) {
		printf("The second win!"); return 0;
	}
	if (a[0][2] > a[1][2]) {
		printf("The first win!"); return 0;
	} 
	if (a[0][2] < a[1][2]) {
		printf("The second win!"); return 0;
	}
	if (a[0][3] > a[1][3]) {
		printf("The first win!"); return 0;
	} 
	if (a[0][3] < a[1][3]) {
		printf("The second win!"); return 0;
	}
}