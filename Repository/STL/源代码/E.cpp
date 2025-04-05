#include<bits/stdc++.h>
using namespace std;
const int MX = 1e5;
map<int,int> m[MX + 10];//map
int n,ans;//城市数量、城市对数
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++)
	{
        string a,b;//城市、州
        cin >> a >> b;
        int A = a[0] * 26 + a[1];
        int B = b[0] * 26 + b[1];
        //把州和城市的前两位分别提取出来hash，然后存到map里
        ans += m[B][A];
        if(A == B)//特殊
        {
        	ans -= m[A][B];//减去
		}
        m[A][B]++;
    }
    cout << ans << endl;
    return 0;
}//20250119//不会的自己看题解