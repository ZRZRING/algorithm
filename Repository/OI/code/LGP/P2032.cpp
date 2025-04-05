#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,a[2000100],q[2000100],p[2000100];
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
int main(){file();
    scanf("%d%d",&n,&m);
    int head=1,tail=0;
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);while (q[tail]<=a[i]&&head<=tail)tail--;
        q[++tail]=a[i];p[tail]=i;
        if (p[head]<=i-m)head++;
        if (i>=m)printf("%d\n",q[head]);
    }
}