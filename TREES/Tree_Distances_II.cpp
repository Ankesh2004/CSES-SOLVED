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

void precomp(ll u, ll parent, unordered_map<ll,vector<ll>>&adj,vector<ll>&cumm,vector<ll>&sum){
    sum[u]=1;
    for(auto v:adj[u]){
        if(v==parent)continue;

        precomp(v,u,adj,cumm,sum);
        sum[u]+=sum[v];
        cumm[u]+=sum[v]+cumm[v];
    }
    return;
}
void dfs(ll u, ll parent, unordered_map<ll,vector<ll>>&adj,vector<ll>&cumm,vector<ll>&sum){
    for(auto v:adj[u]){
        if(v==parent)continue;

        ll newcost=cumm[u]-sum[v]-cumm[v];
        newcost+=sum[u]-sum[v];
        cumm[v]+=newcost;
        sum[v]=sum[u];

        dfs(v,u,adj,cumm,sum);
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
    vector<ll>cumm(n+1,0),sum(n+1,0);
    precomp(1,-1,adj,cumm,sum);
    dfs(1,-1,adj,cumm,sum);

    for(int i=1;i<=n;i++){
        cout<<cumm[i]<<" ";
    }
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
