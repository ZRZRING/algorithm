#include<iostream>
#include<cstring>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<set>
using namespace std;
#define AC 0
#define WA 1

#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=z;x>=y;x--)

int n;
char ans[100005];
char p[100005];
char s[100005];

int main(int argc, char* argv[])
{
    FILE* f_in = fopen(argv[1], "r");//测试输入
    FILE* f_out = fopen(argv[2], "r");//测试输出
    FILE* f_user = fopen(argv[3], "r");//用户输出
    int ret = AC;
    fscanf(f_in, "%d", &n);
    fscanf(f_in, "%s", s);
    fscanf(f_out, "%s", p);
    fscanf(f_user, "%s", ans);
    int flag = 1;
    if (p[0] == '-' && p[1] == '1')
    {
        if (ans[0] == '-' && ans[1] == '1') return ret;
        else return ret = WA;
    }
    set<char>sa;
    rep(i, 0, n - 1) {
        sa.insert(ans[i]);
    }
    if (sa.size() > 2) return WA;
    rep(i, 0, n - 1)
    {
        if (p[i] == ans[i]) continue;
        flag = 0;
        break;
    }
    if (flag == 1) return ret;
    flag = 1;
    rep(i, 0, n - 1)
    {
        int le = i - 1, ri = i + 1;
        if (le < 0) le = n - 1;
        if (ri > n - 1) ri = 0;
        if (s[i] == 'o' && ans[i] == 'S') flag = ans[le] == ans[ri] ? 1 : 0;
        else if (s[i] == 'o' && ans[i] == 'W') flag = ans[le] != ans[ri] ? 1 : 0;
        else if (s[i] == 'x' && ans[i] == 'S') flag = ans[le] != ans[ri] ? 1 : 0;
        else if (s[i] == 'x' && ans[i] == 'W') flag = ans[le] == ans[ri] ? 1 : 0;
        if (flag == 0) break;
    }
    ret = (flag + 1) % 2;
    fclose(f_in);
    fclose(f_out);
    fclose(f_user);
    return ret;
}