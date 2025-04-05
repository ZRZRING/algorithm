#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
void search(int now){
	if (now==1){
		printf("2(0)");
	}else if (now==2){
		printf("2");
	}else if (now==3){
		printf("2+2(0)");
	}else{
		int tmp=now,cnt=0;while (tmp>>=1)cnt++;
		printf("2(");search(cnt);printf(")");
		tmp=now-pow(2,cnt);
		if (tmp){
			printf("+");search(tmp);
		}
	}
}
int main(){
	cin>>n;
	search(n);
}
