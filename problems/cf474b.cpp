// https://codeforces.com/problemset/problem/474/B
// Worms
// BS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define fori(i,a,n) for(int i = a; i < n; i++)

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll n; cin>>n;
    vll v(n); 
    cin >> v[0];
    fori(i,1,n){
        cin >> v[i];
        v[i] += v[i-1];
    }
    ll p;cin>>p;
    ll q;
    while(p--){
        cin>>q;
        ll l=0;
        ll r=n-1;
        while(l<=r){
            ll m = l + (r-l)/2;
            if(v[m]>=q){
                r = m-1;
            }else{
                l=m+1;
            }
        }
        cout << l+1<<endl;
    }

    return 0;
}
