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
const ll MAXN = 1e6+2;


vector<vector<ll>>dp(MAXN,vector<ll>(2,0)); 
void solve() {
    ll n;
    cin>>n;

    cout<<(dp[n-1][0]+dp[n-1][1])%mod<<'\n';
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // precompute
    dp[0][0]=1;
    dp[0][1]=1;

    for(int i=1;i<MAXN;i++){
        dp[i][0]=(dp[i][0]+2LL*dp[i-1][0]+dp[i-1][1])%mod;
        dp[i][1]=(dp[i][1]+4LL*dp[i-1][1]+dp[i-1][0])%mod;
    }

    ll t;cin>>t;
    fri(t)
    solve();
    return 0;
}
