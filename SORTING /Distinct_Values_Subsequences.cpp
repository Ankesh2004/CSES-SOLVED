#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define lld long double
#define pb push_back
#define ff first
#define ss second
#define fri(n) for (int i = 0; i < n; i++)
#define sortv(v) sort((v).begin(), (v).end())
#define printv(v, start_idx)                   \
    for (int i = start_idx; i < v.size(); i++) \
        cout << v[i] << " ";
 
const ll mod = 1e9 + 7;
const ll MAXN = 1002;
 
 
void solve() {
    ll n;
    cin>>n;
    vector<ll>v(n);
    map<ll,ll>mp;
    fri(n){
        cin>>v[i];
        mp[v[i]]++;
    }
    ll ans=1;
    for(auto it:mp){
        ans=(ans*(it.second+1)%mod)%mod;
    }
    ans=(ans-1)%mod;
    cout<<ans<<'\n';

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}
