#include<bits/stdc++.h>
using namespace std;
const int MX = 1e6;
deque<int> d[MX + 10];//˫�˶�������
int m;//һ���ĸ���
void func(string s)//һ�β������ɣ��򵥵�Ҫ����
{
	int a,x;
		 if(s == "push_back") {cin >> a >> x;d[a].push_back(x);}
	else if(s == "pop_back")  {cin >> a;d[a].pop_back();}
	else if(s == "push_front"){cin >> a >> x;d[a].push_front(x);}
	else if(s == "pop_front") {cin >> a;d[a].pop_front();}
	else if(s == "size")      {cin >> a;cout << d[a].size() << '\n';}
	else if(s == "front")     {cin >> a;cout << d[a].front() << '\n';}
	else                      {cin >> a;cout << d[a].back() << '\n';}
}
int main()//������
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m;
    while(m--)//ѭ����ʼ
    {
    	string s;//����
    	cin >> s;
    	func(s);//����
	}
    return 0;
}//20250119