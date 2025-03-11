#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> p(1);
    stack<int>st;

    for(int i=1;i<=n;i++){
        string op;
        cin>>op;
        if(op=="HALT;"){
            string t;
            int b,y;
            cin>>t>>b>>t>>y;
            p.push_back({-1,-1,b,y});
        }else{
            string t;
            int a,b,x,y;
            cin>>a>>t>>x>>t>>b>>t>>y;
            p.push_back({a,x,b,y});
        }
    }

    vector<int> vis;
    
}