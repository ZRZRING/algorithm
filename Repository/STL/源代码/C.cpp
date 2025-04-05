#include<bits/stdc++.h>
using namespace std;
const int MX = 1e6;
int n,i;//操作次数、循环变量
queue<int> q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(i = 1;i <= n;i++)
    {
        int op,x;//操作类型、操作数
        cin >> op;
        if (op == 1)
        {
        	cin >> x;
			q.push(x);//加入
		}
        else if (op == 2)
        {
            if(q.empty())
            {
            	cout << "ERR_CANNOT_POP\n";
				//要判断是否为空，否则RE
			}
            else
            {
            	q.pop();//如果不为空，弹出
			}
        }
        else if(op == 3)
        {
            if (q.empty())
            {
            	cout << "ERR_CANNOT_QUERY\n";
				//要判断是否为空，否则RE
			}
            else
            {
            	cout << q.front() << endl;
				//输出第一个
			}
        }
        else
        {
        	cout << q.size() << endl;
			//输出队列大小
		}
    }
    return 0;
}//20250119