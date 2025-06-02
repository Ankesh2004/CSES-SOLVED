#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define fri(n) for (int i = 0; i < n; i++)
#define sortv(v) sort((v).begin(), (v).end())
#define printv(v, start_idx)                   \
    for (int i = start_idx; i < v.size(); i++) \
        cout << v[i] << " ";

ll mod = 1e9 + 7;
ll MAXN=1e6;

void dfs(ll node,ll parent,unordered_map<ll,vector<ll>>&adj,vector<vector<ll>>&dp){
    // match to parent
    ll sum=0;
    for(auto it:adj[node]){
        if(it==parent)continue;
        dfs(it,node,adj,dp);

        dp[node][1]+=dp[it][0];
        sum+=dp[it][0];
    }
    if(node!=1)dp[node][1]++;
    for(auto it:adj[node]){
        if(it==parent)continue;
        dp[node][0]=max({dp[node][0],(sum-dp[it][0]+dp[it][1]),sum});
    }
    return;
}

void solve(){
    ll n;
    cin>>n;
    unordered_map<ll,vector<ll>>adj;
    ll u,v;
    fri(n-1){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<ll>>dp(n+1,vector<ll>(2,0));
    dfs(1,-1,adj,dp);
    cout<<max(dp[1][0],dp[1][1])<<'\n';

}   

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ll t;
    // cin >> t;
    // fri(t)
        solve();

    return 0;
}
