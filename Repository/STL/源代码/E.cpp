#include<bits/stdc++.h>
using namespace std;
const int MX = 1e5;
map<int,int> m[MX + 10];//map
int n,ans;//�������������ж���
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++)
	{
        string a,b;//���С���
        cin >> a >> b;
        int A = a[0] * 26 + a[1];
        int B = b[0] * 26 + b[1];
        //���ݺͳ��е�ǰ��λ�ֱ���ȡ����hash��Ȼ��浽map��
        ans += m[B][A];
        if(A == B)//����
        {
        	ans -= m[A][B];//��ȥ
		}
        m[A][B]++;
    }
    cout << ans << endl;
    return 0;
}//20250119//������Լ������