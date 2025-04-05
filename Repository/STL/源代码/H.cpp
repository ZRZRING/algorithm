#include<bits/stdc++.h>
using namespace std;
stack<int> s;//栈s
int p,n;//p组数据，n为序列长度 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> p;
	while(p--)
	{
		cin >> n;
		int a[n + 1],b[n + 1],sum = 1;
		//入栈队列a，待检验队列b，计数器sum 
		for(int i = 1;i <= n;i++) cin >> a[i];
		for(int i = 1;i <= n;i++) cin >> b[i];
		for(int i = 1;i <= n;i++)
		{
			s.push(a[i]);//入栈 
			while((s.top()) == b[sum])
			//当栈顶元素与b中当前元素相同时出栈 
			{
				s.pop();
				sum++;
				//sum++到b下一个元素 
				if(s.empty())break;
				//注意这里，当栈空时还用了出栈操作
				//会RE！！！！！所以要手动结束循环 
			}
		}
		if(s.empty()) cout << "Yes" << endl;
		//如果栈为空说明出栈序列b正确 
		else cout << "No" << endl;
		while(!s.empty()) s.pop();
		//清空栈 不然爆零
	}
    return 0;
}//20250119