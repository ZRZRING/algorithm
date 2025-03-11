#include <bits/stdc++.h>

#define LL long long

inline int read() {
    bool sym = false; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

int main() {
    std::stack<int> A, B;
    int n = read(), a[n + 1], max = -2e9, cnt = 0;
    for (int i = 1; i <= n; i++) a[i] = read();
    A.push(a[1]);
    for (int i = 2; i <= n; i++) {
        if (a[i] < A.top()) {A.push(a[i]); continue;}
		if (B.size() == 0 || a[i] > B.top()) {B.push(a[i]); continue;}
		max = std::max(max, (int)(A.size()));
		while (A.size()) A.pop(); cnt++;
		while (B.size() && B.top() > a[i]) {A.push(B.top()); B.pop();}
		A.push(a[i]);
    }
    if (A.size()) {
        max = std::max(max, (int)A.size()); cnt++;
    }
    if (B.size()) {
        max = std::max(max, (int)B.size()); cnt++;
    }
    printf("%d %d\n", cnt, max);
    return 0;
}
