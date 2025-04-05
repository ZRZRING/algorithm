#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
queue <string> q;
queue <int> qa;
queue <int> qz;
string begin,end,now,tmps;
map<string,int>mp;
int head=0,tail=1,p,z,tmp1,tmp2,tmp,a,b;
int power(int a,int b){
	int ans=1;
	while (b--){
		ans*=a;
	}
	return ans;
}
int main(){
    cin>>begin>>end;q.push(begin);qa.push(0);qz.push(0);
    while (!q.empty()){
        now=q.front();p=qa.front();z=qz.front()+1;tmps=now;
        q.pop();qa.pop();qz.pop();
        if (now==end){
            cout<<z-1;return 0;
        }
        //cout<<mp[now]<<' '<<p<<endl;
        if ((mp[now]>>p)&1)continue;
        //cout<<now<<' '<<p<<' '<<z<<endl;
        mp[now]+=power(2,p);
        if (p!=0){//某位和0交换
            swap(now[0],now[p]);
            q.push(now);qa.push(p);qz.push(z);
            now=tmps;
        }
        if (p!=5){//某位和5交换
            swap(now[5],now[p]);
            q.push(now);qa.push(p);qz.push(z);
            now=tmps;
        }
        if (now[p]!='9'){//++
            now[p]++;q.push(now);qa.push(p);qz.push(z);
            now=tmps;
        }
        if (now[p]!='0'){//--
            now[p]--;q.push(now);qa.push(p);qz.push(z);
            now=tmps;
        }
		if (p!=0){//左移1
            q.push(now);qa.push(p-1);qz.push(z);
        }
        if (p!=5){//右移1
            q.push(now);qa.push(p+1);qz.push(z);
        }
    }
}
