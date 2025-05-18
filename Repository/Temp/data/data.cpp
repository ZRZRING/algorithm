# include <bits/stdc++.h>
using namespace std;
# define N 1000005
int A[N],n,m,W;
map<int,int>mp;
int main()
{
    srand(time(0));
    freopen("01.in","w",stdout);
    n=5;
    m=8; 
    W=rand()%1000;
    for(int i=1;i<=n;i++)
    {
        A[i]=i;
    }
    for(int i=1;i<=n;i++) 
    {
        int j=1+rand()%i;
        swap(A[i],A[j]);
    }
    printf("%d %d %d\n",n,m,W);
	for(int i = 1;i<=n;i++){
		int w = 1+rand()%W;
		int v = 1+rand()%1000;
		printf("%d %d\n",w,v);
	}       
    for(int i=2;i<=n;i++)
    { 
        int j=1+rand()%(i-1);
        int z=1+rand()%1000;
        printf("%d %d %d\n",A[i],A[j],z);
    }
    for(int i=n;i<=m;i++)
    {
    	int x=1+rand()%n;
    	int y=1+rand()%n;
    	int z=1+rand()%1000;
    	if(A[x]>A[y])swap(x,y);
    	while(mp[A[x]] == A[y] || mp[A[y]] == A[x] || A[x] == A[y]){
    		x=1+rand()%n,y=1+rand()%n;	
		}
		if(A[x]>A[y])
			swap(x,y);
		mp[A[x]] = A[y];
		mp[A[y]] = A[x];
    	printf("%d %d %d\n",A[x],A[y],z);
	}
    return 0;
}
