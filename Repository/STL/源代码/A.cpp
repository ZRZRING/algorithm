#include<bits/stdc++.h>
using namespace std;
const int MX = 1e6;//ֱ�������Ҳ���
//1e5 * 1e5�Ķ�ά����϶�MLE
int n,q,p,k;//������������������������͡���Ʒ
map<long long,int> b;//��ʽ�ṹѹ���ռ䡢ʱ��
long long i,j;//��������
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);//�ر���ͬ��
    cin >> n >> q;
	while(q--)//ѭ����ʼ
	{
		cin >> p >> i >> j;//����������͡���������
		if(p == 1)//����Ǵ���
		{
			cin >> k;//������Ʒ��k = 0������գ�
			b[i * MX + j] = k;
			/*������ά���ݶ���1e5�ķ�Χ�ڣ�
			���ǿ���ͨ��һЩ�Ƚ�����ķ�����
			��һά���ݳ���1e5,�ټ�����һά���ݣ�
			������int���͵�����ѹ��һ��
			long long���͵�����,��ʡ�ռ䣬��ֹMLE��
			ͬʱ������MX����������ڽ��в���*/
		}
		else//����ǲ�ѯ
		{
			cout << b[i * MX + j] << '\n';//������
		}
	}
    return 0;
}//20250119