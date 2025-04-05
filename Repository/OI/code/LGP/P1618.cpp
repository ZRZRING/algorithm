#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int d[11]={0,1,2,3,4,5,6,7,8,9};
int ans,a,b,c;
int main(){
	cin>>a>>b>>c;
	if ((100*d[1]+10*d[2]+d[3])*b*c==(100*d[4]+10*d[5]+d[6])*a*c&&(100*d[4]+10*d[5]+d[6])*a*c==(100*d[7]+10*d[8]+d[9])*b*a){
		cout<<d[1]<<d[2]<<d[3]<<" "<<d[4]<<d[5]<<d[6]<<" "<<d[7]<<d[8]<<d[9]<<endl;
			 ans++;
	}
	for (;next_permutation(d+1,d+10);){
		if ((100*d[1]+10*d[2]+d[3])*b*c==(100*d[4]+10*d[5]+d[6])*a*c&&(100*d[4]+10*d[5]+d[6])*a*c==(100*d[7]+10*d[8]+d[9])*b*a){
			 cout<<d[1]<<d[2]<<d[3]<<" "<<d[4]<<d[5]<<d[6]<<" "<<d[7]<<d[8]<<d[9]<<endl;
			 ans++;
		}
	}
	if (!ans)cout<<"No!!!";
} 
