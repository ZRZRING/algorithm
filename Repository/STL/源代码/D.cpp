#include<bits/stdc++.h>
using namespace std;
const int MX = 1e5;
int a[MX + 10],b[MX + 10],c[MX + 10],d[MX + 10];
//��������O(��_��)O
int k,g,f,m,q;//����Ա���������г���ǰ�桢����
double tbh;//ʵ��ֵ
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> k >> g >> f >> m;
    for(int i = 1;i <= k;i++) cin >> a[i];
    for(int i = 1;i <= g;i++) cin >> b[i];
    for(int i = 1;i <= f;i++) cin >> c[i];
    for(int i = 1;i <= m;i++) cin >> d[i];
    sort(a + 1,a + k + 1,greater<int>());
    sort(b + 1,b + g + 1,greater<int>());
    sort(c + 1,c + f + 1,greater<int>());
    sort(d + 1,d + m + 1,greater<int>());
    cin >> q;
    int l,z,y;//�������е�Ai,Bi,Ci
    int x = 1,r = 1,w = 1,h = 1;//�ܹ�������
    while(q--)
	{
    	cin >> l >> z >> y;
    	tbh = 0;
    	tbh += a[x];//����Ա
    	x++;//���++
    	for(int i = r;i < r + l;i++) tbh += b[i];//����
    	r += l;
    	for(int i = w;i < w + z;i++) tbh += c[i];//�г�
    	w += z;
    	for(int i = h;i < h + y;i++) tbh += d[i];//ǰ��
    	h += y;
    	cout << fixed << setprecision(2) << 
		tbh * 1.0 / 11 << endl;
    }
    return 0;
}//20250119