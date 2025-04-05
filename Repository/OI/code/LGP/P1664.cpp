#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
/*
1天：奖励1
3天：奖励2
7天：奖励3
30天：奖励4
120天：奖励5
365天：奖励6
*/
using namespace std;
int n,score[100010],a,down=1,cnt,ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=2;i++)score[i]=1;
	for (int i=3;i<=6;i++)score[i]=2;
	for (int i=7;i<=29;i++)score[i]=3;
	for (int i=30;i<=119;i++)score[i]=4;
	for (int i=120;i<=364;i++)score[i]=5;
	for (int i=365;i<=3000;i++)score[i]=6;
	for (int i=1;i<=n;i++){
		scanf("%d",&a);
		if (a){
			if (down){
				cnt=max(cnt-down,0);down=0;
			}ans+=score[++cnt];
		}else{
			if (!down)down=1;else down<<=1;
		}
	}
	printf("%d",ans);
}
