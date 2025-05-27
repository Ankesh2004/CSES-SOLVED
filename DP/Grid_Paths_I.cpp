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
    ll n;cin>>n;
    char c;
    vector<vector<ll>>v(n+1,vector<ll>(n+1,0));
    vector<vector<ll>>dp(n+1,vector<ll>(n+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>c;
            if(c=='*')v[i][j]=-1;
        }
    }
    if(v[1][1]==-1){
        cout<<0;
        return;
    }
    dp[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(v[i][j]==-1 || (i==1 && j==1))continue;;
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
        }
    }
    cout<<dp[n][n]<<'\n';


}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}
