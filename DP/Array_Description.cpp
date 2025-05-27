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
    ll n,m;cin>>n>>m;
    vector<ll>v(n);
    fri(n){
        cin>>v[i];
    }
    if(m==1){
        cout<<1<<'\n';
        return;
    }
    vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
    if(v[0]==0){
        fri(m){
            dp[1][i+1]=1;
        }
    }
    else{
        dp[1][v[0]]=1;
    }

    for(int i=2;i<=n;i++){
        if(v[i-1]!=0){
            dp[i][v[i-1]]=(dp[i][v[i-1]]+dp[i-1][v[i-1]])%mod;
            if(v[i-1]<m)dp[i][v[i-1]]=(dp[i][v[i-1]]+dp[i-1][v[i-1]+1])%mod;
            if(v[i-1]>1)dp[i][v[i-1]]=(dp[i][v[i-1]]+dp[i-1][v[i-1]-1])%mod;
        }
        else{
            for(int j=1;j<=m;j++){
                dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
            if(j<m)dp[i][j]=(dp[i][j]+dp[i-1][j+1])%mod;
            if(j>1)dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
            }
        }
    }
    ll ans=0;
    if(v[n-1]==0){
        fri(m){
            ans=(ans+dp[n][i+1])%mod;
        }
    }
    else{
        ans=dp[n][v[n-1]];
    }
    cout<<ans<<'\n';

}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}
