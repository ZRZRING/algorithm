#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
struct PLAYER{
	string fname,lname;
	int score,level;
}player[100010];
int cmp(PLAYER a,PLAYER b){
	return a.score>b.score;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		cin>>player[i].fname>>player[i].lname>>player[i].score>>player[i].level;
	}
	sort(player+1,player+n+1,cmp);
	for (int i=1;i<=n;i++){
		cout<<player[i].fname<<' '<<player[i].lname<<' '<<player[i].level<<endl;
	}
}
