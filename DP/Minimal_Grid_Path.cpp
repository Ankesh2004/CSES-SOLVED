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
    ll n;cin>>n;
    vector<vector<char>>v(n,vector<char>(n));
    vector<vector<ll>>mv(n,vector<ll>(n,0));
    vector<vector<pair<char,ll>>>dp(n,vector<pair<char,ll>>(n,{'Z',-1})); // {maxchar, first pos}
    char c;
    fri(n){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    dp[0][0]={v[0][0],0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>0){
                if(v[i][j]>dp[i-1][j].ff)dp[i][j]={v[i][j],i+j};
                else dp[i][j]=dp[i-1][j];

                mv[i][j]=1;
            }
            if(j>0){
                if(v[i][j]>dp[i][j-1].ff)dp[i][j]={v[i][j],i+j};
                else dp[i][j]=dp[i][j-1];
            
                mv[i][j]=2;
            }
            if(i>0 && j>0){
                if(dp[i-1][j].ff < dp[i][j-1].ff || (dp[i-1][j].ff==dp[i][j-1].ff && dp[i-1][j].ss < dp[i][j-1].ss)){
                    mv[i][j]=1;
                }
                else{
                    mv[i][j]=2;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j].ff<<"-"<<dp[i][j].ss<<" ";
        }
        cout<<'\n';
    }

   string s="";
   ll x=n-1,y=n-1;
   while(x>=0 && y>=0){
    s.pb(v[x][y]);
    if(mv[x][y]==1){
        x--;
    }
    else y--;
   }
   cout<<s<<'\n';
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}
