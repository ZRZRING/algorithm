#include<bits/stdc++.h>
using namespace std;
stack<int> s;//ջs
int p,n;//p�����ݣ�nΪ���г��� 
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
		//��ջ����a�����������b��������sum 
		for(int i = 1;i <= n;i++) cin >> a[i];
		for(int i = 1;i <= n;i++) cin >> b[i];
		for(int i = 1;i <= n;i++)
		{
			s.push(a[i]);//��ջ 
			while((s.top()) == b[sum])
			//��ջ��Ԫ����b�е�ǰԪ����ͬʱ��ջ 
			{
				s.pop();
				sum++;
				//sum++��b��һ��Ԫ�� 
				if(s.empty())break;
				//ע�������ջ��ʱ�����˳�ջ����
				//��RE��������������Ҫ�ֶ�����ѭ�� 
			}
		}
		if(s.empty()) cout << "Yes" << endl;
		//���ջΪ��˵����ջ����b��ȷ 
		else cout << "No" << endl;
		while(!s.empty()) s.pop();
		//���ջ ��Ȼ����
	}
    return 0;
}//20250119