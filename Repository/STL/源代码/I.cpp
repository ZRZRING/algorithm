#include<bits/stdc++.h>
using namespace std;
const int MX = 1e6;
int f[20][20],n;//��¼���顢����
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0;i <= n;i++) f[i][0] = 1;
	//�߽�һ��Ҫ��
    for(int j = 1;j <= n;j++)
    {
    	for(int i = 0;i <= n;i++)
       //����Ҫ��f[0][n]������iҪ���㿪ʼ��
        {
          if(i >= 1) 
		  f[i][j] = f[i - 1][j] + f[i + 1][j - 1];
          if(i == 0)/*ջ��û�ж���*/ 
		  f[i][j] = f[i +1 ][j - 1];
        }
	}
    cout << f[0][n] << endl;
    return 0;
}//20250119