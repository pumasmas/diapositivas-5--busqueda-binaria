// https://codeforces.com/problemset/problem/1742/E
// BS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll; 
#define fi first
#define se second
#define fori(i,a,n) for(int i = a; i < n; i++)
#define endl '\n'
#define all(v) v.begin(),v.end()

void fastIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve() {
    ll n, q; cin>>n>>q;
    vpll v(n);
    
    ll h;
    cin >> h;
    
    v[0] = {h,h};
    fori(i,1,n){
        cin >> h;
        ll maximo = max(v[i-1].fi, h);
        ll acc = v[i-1].se + h;
        
        v[i] = {maximo,acc};

    }
    
    ll k;
    while(q--) {
        cin >> k;
        
        ll idx = -1;
        ll l=0,r=n-1;
        while (l<=r){
            ll m = l + (r-l) / 2;
            if (v[m].fi > k){
                r=m-1;
            }else{
                idx = m;
                l=m+1;
            }
        }
        cout <<((idx==-1) ? 0 : v[r].se) << " ";
    }
    cout << endl;
}

int main() {
    fastIO();
    int testCases;cin >> testCases;while( testCases-- ) {solve();}
    return 0;
}
