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
    string s1,s2;
    cin>>s1>>s2;
    if(s1.size()>s2.size())swap(s1,s2);
    ll n1=s1.size(),n2=s2.size();
    vector<vector<ll>>dp(n1+1,vector<ll>(n2+1,0));
    fri(n1+1)dp[i][0]=i;
    fri(n2+1)dp[0][i]=i;

    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=min({dp[i-1][j-1],dp[i][j-1]+1,dp[i-1][j]+1});
            }
            else{
                dp[i][j]=min({dp[i-1][j-1]+1,dp[i][j-1]+1,dp[i-1][j]+1});
            }
        }
    }
    cout<<dp[n1][n2]<<'\n';
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}
