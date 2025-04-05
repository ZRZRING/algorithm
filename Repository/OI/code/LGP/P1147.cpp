#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int main(){
    cin>>n;n<<=1;
    for (int i=sqrt(n);i>1;i--){
        if (n%i==0 && n/i%2!=i%2){
            int k1=i,k2=n/i;
            cout<<(k2-k1+1)/2<<' '<<(k1+k2-1)/2<<endl;
        }
    }
}