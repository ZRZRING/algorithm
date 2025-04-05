#include<bits/stdc++.h>
using namespace std;
set<int> s;//set
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,i,x,cnt = 0;
	//个数、循环变量、元素、查重后的个数
    cin >> n;
    for(i = 1;i <= n;i++)
    {
    	cin >> x;
    	s.insert(x);//插入x
	}
	for(auto e : s)//记得！记得！
	{
		cnt++;
	}
	cout << cnt << endl;
	for(auto e : s)
	{
		cout << e << " ";
	}
    return 0;
}//20250119