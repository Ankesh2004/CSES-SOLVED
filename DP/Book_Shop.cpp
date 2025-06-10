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
ll x;
ll f(vector<vector<ll>>&dp,ll i,ll price,vector<ll>&h,vector<ll>&s){
    if(i==h.size()){
        return 0;
    }
    if(dp[i][price]!=-1){
        return dp[i][price];
    }
    ll nottake=f(dp,i+1,price,h,s);
    ll take=0;
    if((h[i]+price)<=x){
        take=s[i]+f(dp,i+1,price+h[i],h,s);
    }
    return dp[i][price]=max(nottake,take);
}
 
void solve() {
    ll n,k;
    cin>>n>>k;
    x=k;
    vector<ll>h(n),s(n);
    fri(n){
        cin>>h[i];
    }
    fri(n){
        cin>>s[i];
    }

    // vector<vector<ll>>dp(n+1,vector<ll>(x+1,0));
    // ll ans=f(dp,0,0,h,s);
    // cout<<ans<<'\n';

    vector<ll>dp(k+1,0);

    for(int i=0;i<n;i++){
        for(int j=k;j>=h[i];j--){
            dp[j]=max(dp[j],dp[j-h[i]]+s[i]);
        }
    }
    cout<<dp[k]<<'\n';

}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}
