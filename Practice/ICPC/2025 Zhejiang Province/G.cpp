#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5+7,mod=1e9+7,INF=1e18;
#define endl '\n'

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> num(n + 1), ve(n + 1);

    double ans = 1;
    auto col = [&](ll lc) -> double{
        double num2 = ve[lc] / 100.;
        double num3 = ans / (1 + ve[lc] * num[lc] / 100.);
        return num2 * num3;
    };

    if(k <= 1000){
        for(ll i = 1; i <= n; i++){
            num[i] = 0;
            cin >> ve[i];
        }
        sort(ve.begin() + 1, ve.end(), greater<ll>());
        num[1] = 1; 
        k -= 1;
        ans = 1 + ve[1] / 100.;

        for(ll i = 1; i <= k; i++){
            ll loc = 1;
            double max1 = 0;
            for(ll j = 1; j <= n; j++){
                double a = col(j);
                if(a > max1){
                    max1 = a;
                    loc = j;
                }
            }
            ans += max1;
            num[loc]++;
        }
    }else{
        int kk = k;
        for(ll i = 1; i <= n; i++){
            num[i] = k / n - 10.;
            kk -= num[i];
            cin >> ve[i];
            ans *= 1 + ve[i] * num[i] / 100.;
        }
        sort(ve.begin() + 1, ve.end(), greater<ll>());
        k = kk;
        for(ll i = 1; i <= k; i++){
            ll loc = 1;
            double max1 = 0;
            for(ll j = 1; j <= n; j++){
                double a = col(j);
                if(a > max1){
                    max1 = a;
                    loc = j;
                }
            }
            ans += max1;
            num[loc]++;
        }
    }


    // for(ll i = 1; i <= n; i++) cout << ve[i] << " ";
    // cout << endl;
    // for(ll i = 1; i <= n; i++) cout << num[i] << " ";
    // cout << endl;

    cout << ans << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}