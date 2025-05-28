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
const ll MAXN = 1e5+6;

 
void solve() {
    ll a,b;cin>>a>>b;
    vector<vector<ll>>dp(a+1,vector<ll>(b+1,1e18));
    for (int i = 0; i <= a; i++) dp[i][0] = 0;
    for (int j = 0; j <= b; j++) dp[0][j] = 0;

    fri(min(a+1,b+1)){
        dp[i][i]=0;
    }

    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==j)continue;
            for(int x=1;x<j;x++){
                dp[i][j]=min(dp[i][j],dp[i][x]+dp[i][j-x]+1);
            }
            for(int x=1;x<i;x++){
                dp[i][j]=min(dp[i][j],dp[x][j]+dp[i-x][j]+1);
            }
            
        }
    }
    cout<<dp[a][b]<<'\n';
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}
