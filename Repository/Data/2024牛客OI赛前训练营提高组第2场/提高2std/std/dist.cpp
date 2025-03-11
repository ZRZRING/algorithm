#include <bits/stdc++.h>
using namespace std;

const int N = 5000005;

int type;

char a[N];
int n;

int calc_max() {
    int ptr = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] != a[1]) {
            ptr = i;
            break;
        }
    }
    if (ptr) {
        return n + (n - ptr + 1);
    } else {
        return n - 1;
    }
}
int calc_min() {
    if (a[n - 1] == a[n]) return 1;
    if (a[n - 2] == a[n]) return 2;
    return 3;
}

void sc() {
    scanf("%s", a + 1);
    n = strlen(a + 1);
    if (type != 1) printf("%d ", calc_max());
    if (type != 0) printf("%d ", calc_min());
    puts("");
}

int main() {
    int T;
    scanf("%d%d", &T, &type);
    while (T--) sc();
    return 0;
}