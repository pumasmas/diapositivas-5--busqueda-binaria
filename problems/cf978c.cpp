// https://codeforces.com/problemset/problem/978/C
// Letters
// BS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(a) (int)(a.size())
#define fori(i,a,n) for(int i = a; i < n; i++)
#define endl '\n'
#define print(v) for(auto &i : v) {cout << i << ' ';} cout << endl;

void fastIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve() {
    ll n, m;cin>>n>>m;
    vll tags(n);
    vll v(n);
    cin>>v[0];
    tags[0] = v[0];
    fori(i,1,n){
        cin >> v[i];
        // cout << v[i]<<endl;
        tags[i] = v[i];
        v[i]+=v[i-1];
    }
    // print(v);
    ll q;
    while(m--){
        cin>>q;
        ll idx = lower_bound(all(v),q) - v.begin();
        // cout <<idx;
        if (idx==0){
            cout << idx+1 << " " << q;
        }else{
            cout << idx+1 << " " << q - v[idx-1];
        }
        cout << endl;
    }
}

int main() {
    fastIO();
    solve();
    return 0;
}
