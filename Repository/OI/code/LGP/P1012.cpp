#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
string str[21];
int cmp(string a,string b){
	return a+b>b+a;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>str[i];
	}
	sort(str+1,str+n+1,cmp);
	for (int i=1;i<=n;i++){
		for (int j=0;j<=str[i].length()-1;j++){
			cout<<str[i][j];
		}
	}
}
