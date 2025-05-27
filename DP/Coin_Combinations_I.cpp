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
    ll n,k;
    cin>>n>>k;
    vector<ll>v(n);
    fri(n)cin>>v[i];
    vector<ll>dp(k+1,0);
    dp[0]=1;

    fri(k+1){
        for(int j=0;j<n;j++){
            if((i-v[j])>=0){
                dp[i]=(dp[i]+dp[i-v[j]])%mod;
            }
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
