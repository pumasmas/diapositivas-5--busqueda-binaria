// https://codeforces.com/contest/1873/problem/E
// Building an Aquarium
// BS on the answer
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
    ll n; cin>>n; ll x;cin>>x;
    vector<ll> a(n); for(auto &i:a)cin>>i;
    ll l=0, r=1e14;
    auto bs=[&](ll m){
        ll s = 0;
        for(ll e: a){
            s += max(m-e, 0LL);
            if (s>x) return false;
        }
        return true;
    };
    while(l<r){
        ll m=l+(r-l+1)/2;
        if(bs(m)){
            l=m;
        }else{
            r = m-1;
        }
    }
    cout << l <<'\n';
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
