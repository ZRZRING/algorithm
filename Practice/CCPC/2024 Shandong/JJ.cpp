#include <bits/stdc++.h>
using namespace std;
#define IOS \
    std::ios::sync_with_stdio(0), \
    std::cin.tie(0), \
    std::cout.tie(0)
struct node{
    int x,y,z,val;
};
void solve(){
    int n;
    cin>>n;
    vector<node> p(n+1);
    std::vector<std::map<int, std::set<int>>> cnt(3);
    vector a(3, std::map<int, set<int>>()) ;  //受该纬影响的点
    for(int i=1;i<=n;i++){
        int x,y,z;
        p[i]={x,y,z};
        cnt[0][x]++;
        cnt[1][y]++;
        cnt[2][z]++;
    }
    set<int>t[n+1];  //密度为i的点
    for(int i=1;i<=n;i++){
        int x=p[i].x,y=p[i].y,z=p[i].z;
        p[i].val=max({cnt[0][x],cnt[1][y],cnt[2][z]});
        if(p[i].val==cnt[0][x]) a[0][x].insert(i);
        if(p[i].val==cnt[1][y]) a[1][y].insert(i);
        if(p[i].val==cnt[2][z]) a[2][z].insert(i);
        t[p[i].val].insert(i);
    }
    for(auto qqq:t[1])
        cout<<qqq;
    for(int i=1;i<=n;i++){
        for(auto j:t[i]){
            int x=p[i].x,y=p[i].y,z=p[i].z;
            cnt[0][x]--,cnt[1][y]--,cnt[2][z]--;
            vector<node> temp;
            for(auto k:a[0][x]){
                int xx=p[k].x,yy=p[k].y,zz=p[k].z;
                p[k].val=max({cnt[0][xx],cnt[1][yy],cnt[2][zz]});
                if(p[k].val==cnt[0][xx]) temp.push_back({0,xx,k});
                if(p[k].val==cnt[1][yy]) temp.push_back({1,yy,k});
                if(p[k].val==cnt[2][zz]) temp.push_back({2,zz,k});
            }
            a[0][x].clear();
            for(auto o:temp){
                a[o.x][o.y].insert(o.z);
            }
        }
    }

}

int main() {
    // IOS;
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}
