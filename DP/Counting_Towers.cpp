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

    vector<ll>dp(n+1,0);
    dp[1]=2;

    for(int i=2;i<=n;i++){
        for(int x=1;x<=(i/2);x++){
            dp[i]=(dp[i]+2*(dp[i-x]*dp[x]) % mod) % mod;
        }
    }
    cout<<dp[n]<<'\n';
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;cin>>t;
    fri(t)
    solve();
    return 0;
}
