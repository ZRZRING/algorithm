#include<bits/stdc++.h>
using namespace std;
const int MX = 1e6;
int n,i;//����������ѭ������
queue<int> q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(i = 1;i <= n;i++)
    {
        int op,x;//�������͡�������
        cin >> op;
        if (op == 1)
        {
        	cin >> x;
			q.push(x);//����
		}
        else if (op == 2)
        {
            if(q.empty())
            {
            	cout << "ERR_CANNOT_POP\n";
				//Ҫ�ж��Ƿ�Ϊ�գ�����RE
			}
            else
            {
            	q.pop();//�����Ϊ�գ�����
			}
        }
        else if(op == 3)
        {
            if (q.empty())
            {
            	cout << "ERR_CANNOT_QUERY\n";
				//Ҫ�ж��Ƿ�Ϊ�գ�����RE
			}
            else
            {
            	cout << q.front() << endl;
				//�����һ��
			}
        }
        else
        {
        	cout << q.size() << endl;
			//������д�С
		}
    }
    return 0;
}//20250119