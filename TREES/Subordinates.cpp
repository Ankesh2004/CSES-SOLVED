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

ll dfs(ll node,unordered_map<int,vector<int>>&adj,vector<ll>&childs){
    if(adj[node].size()==0){
        childs[node]=0;
        return 1;
    }
    for(auto it:adj[node]){
        childs[node]+=dfs(it,adj,childs);
    }
    if(node==0)return childs[0];
    return 1+childs[node];
}

void solve(){
    ll n;
    cin>>n;
    unordered_map<int,vector<int>>adj;
    ll x;
    fri(n-1){
        cin>>x;
        x--;
        adj[x].push_back(i+1);
    }
    vector<ll>childs(n,0);
    childs[0]=dfs(0,adj,childs);
    printv(childs,0);cout<<'\n';

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
