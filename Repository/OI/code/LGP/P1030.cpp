#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
string inde,last;
void search(string inde,string last){
	if (inde.size()<=0)return;
	char k=last[last.size()-1];
	cout<<k;int op=inde.find(k);
	search(inde.substr(0,op),last.substr(0,op));
	search(inde.substr(op+1),last.substr(op,inde.size()-op-1));
}
int main(){
	cin>>inde>>last;
	search(inde,last);
}
