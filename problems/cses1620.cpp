// https://cses.fi/problemset/task/1620/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vll=vector<ll>;
#define all(a) a.begin(), a.end()
#define cinv(a) for(auto &i:a)cin>>i
ll n, t, ans;
vll a;
void solve(){
    cin>>n>>t; a.resize(n); cinv(a);
    ll l=1, r=(*min_element(all(a))) * t;
    auto f = [&](ll m){
        ll prod=0;
        for(ll x:a){
            prod += m / x;
            if (prod>=t) return true;
        }
        return false;
    };
    while (l <= r){
        ll m = l + (r-l)/2;
        if (f(m)){
            ans=m;
            r = m-1;
        }else{
            l = m+1;
        }
    }
    cout<< ans <<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(nullptr);
  solve();
  return 0;
}
