#include <bits/stdc++.h>

using namespace std;

int dis(int x0, int y0, int x1, int y1) {
    return (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        vector<int> x(4), y(4), id(4);
        for (int i = 0; i < 4; i++) {
            cin >> x[i] >> y[i];
            id[i] = i;
        }
        int flag = 0;
        do {
            int x0 = x[id[0]], y0 = y[id[0]];
            int x1 = x[id[1]], y1 = y[id[1]];
            int x2 = x[id[2]], y2 = y[id[2]];
            int x3 = x[id[3]], y3 = y[id[3]];
            if ((y0 - y1) * (x2 - x3) == (y2 - y3) * (x0 - x1)) {
                if ((y0 - y2) * (x1 - x3) != (y1 - y3) * (x0 - x2)) {
                    if (dis(x0, y0, x2, y2) == dis(x1, y1, x3, y3)) {
                        flag = 1;
                    }
                }
            }
        } while (next_permutation(id.begin(), id.end()));
        if (flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}