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
 
ll f(ll v,vector<ll>&dp){
    if(v<=0){
        if(v==0)return 0;
        return 1e18;
    }
    if(dp[v]!=-1){
        return dp[v];
    }
    ll steps=1e18;
    string s=to_string(v);
    for(auto c:s){
        ll val=c-'0';
        if(val>0){
            steps=min(steps,1+f(v-val,dp));
        }
    }
    return dp[v]=steps;
}
void solve() {
    ll n;cin>>n;
    vector<ll>dp(n+1,-1);
    ll ans=f(n,dp);
    cout<<ans<<'\n';
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}
