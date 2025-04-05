#include<bits/stdc++.h>
using namespace std;
stack<int> st;//栈
void func(string s)//按规定操作即可
{
	int x;
	if(s == "push"){cin >> x;st.push(x);}
	else if(s == "pop")
	{
		if(st.empty()) cout << "Empty" << endl;
		else st.pop();
	}
	else if(s == "query")
	{
		if(st.empty()) cout << "Anguei!" << endl;
		else cout << st.top() << endl;
	}
	else cout << st.size() << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T,n;
    cin >> T;
    while(T--)
    {
    	cin >> n;
    	for(int i = 1;i <= n;i++)
    	{
    		string s;
    		cin >> s;
    		func(s);//副函数
		}
	}
    return 0;
}//20250119