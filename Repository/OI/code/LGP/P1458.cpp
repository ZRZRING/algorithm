#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int n;
/*void DFS(const int& l1, const int& l2, const int& r1, const int& r2)
{
    if(l2 > N || r2 > N)
        return;

    DFS(l1, l2, l1 + r1, l2 + r2);
    if(l2 + r2 <= N)
        printf("%d/%d\n", l1 + r1, l2 + r2);
    DFS(l1 + r1, l2 + r2, r1, r2);
}*/
void dfs(int l1,int l2,int r1,int r2){
	if (l2>=n+1||r2>=n+1){
		return;
	}
	dfs(l1,l2,l1+r1,l2+r2);
	if (l2+r2<n){
		cout<<l1+r1<<'/'<<l2+r2<<endl;
	} 
	dfs(l1+r1,l2+r2,r1,r2); 
}
int main(){
	cin>>n;
	cout<<"0/1"<<endl;
	dfs(0,1,1,1);
	cout<<"1/1";
} 
