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

void dfs(ll node, ll parent, unordered_map<ll,vector<ll>>&adj, ll&mx, ll&s, ll curr){
    if(curr > mx){
        mx = curr;
        s = node;
    }
    for(auto it : adj[node]){
        if(it != parent){
            dfs(it, node, adj, mx, s, curr + 1);
        }
    }
}

void dfsd(ll node, ll parent, unordered_map<ll,vector<ll>>&adj, ll&ans, ll depth){
    ans = max(ans, depth);
    for(auto it : adj[node]){
        if(it != parent){
            dfsd(it, node, adj, ans, depth + 1);
        }
    }
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
    ll mx=0,s=1,ans=0;
    dfs(1, -1, adj, mx, s, 0);
    dfsd(s, -1, adj, ans, 0);
    
    cout<<ans<<'\n';
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
