#include<bits/stdc++.h>
using namespace std;
const int MX = 1e6;//直觉告诉我不简单
//1e5 * 1e5的二维数组肯定MLE
int n,q,p,k;//包柜个数、操作数、操作类型、物品
map<long long,int> b;//链式结构压缩空间、时间
long long i,j;//横纵坐标
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);//关闭流同步
    cin >> n >> q;
	while(q--)//循环开始
	{
		cin >> p >> i >> j;//读入操作类型、横纵坐标
		if(p == 1)//如果是存入
		{
			cin >> k;//输入物品（k = 0则是清空）
			b[i * MX + j] = k;
			/*由于两维数据都在1e5的范围内，
			我们可以通过一些比较玄妙的方法，
			将一维数据乘上1e5,再加上另一维数据，
			把两个int类型的数据压成一个
			long long类型的数据,节省空间，防止MLE，
			同时乘上了MX，区别大，利于进行查找*/
		}
		else//如果是查询
		{
			cout << b[i * MX + j] << '\n';//输出情况
		}
	}
    return 0;
}//20250119