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
ll MAXN=2e5+5;
ll LOGN = 30;

vector<vector<ll>>up(MAXN,vector<ll>(LOGN));

void precomp(ll n){
    for(int i=1;i<=LOGN;i++){
        for(int j=1;j<=n;j++){
            up[j][i]=up[up[j][i-1]][i-1];
        }
    }
}
ll query(ll u,ll k){
    ll x=u;
    for(int i=0;i<=30;i++){
        if(k&(1<<i)){
            x=up[x][i];
        }
    }
    return x;
}
void calcDep(ll node,ll d,vector<ll>&depth,unordered_map<ll,vector<ll>>&adj){
    depth[node]=d;
    for(auto it:adj[node]){
        calcDep(it,d+1,depth,adj);
    }
    return;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    unordered_map<ll,vector<ll>>adj;
    for(int i=2;i<=n;i++){
        cin>>up[i][0];
        adj[up[i][0]].push_back(i);
    }
    precomp(n);
    
    ll u,v;
    vector<ll>depth(n+1,0);
    calcDep(1,0,depth,adj);

    fri(m){
        cin>>u>>v;
        ll d1=depth[u],d2=depth[v];
        if(d1>d2){
            u=query(u,d1-d2);
        }
        else if(d2>d1){
            v=query(v,d2-d1);
        }
        // cout<<u<<" "<<v<<'\n';

        // same level - done
        if(u==v){
            cout<<u<<'\n';
            continue;
        }
        for(int i=LOGN-1;i>=0;i--){
            if(up[u][i] != 0 && up[v][i] != 0 && up[u][i] != up[v][i]){
                u = up[u][i];
                v = up[v][i];
            }
        }
        cout<<up[u][0]<<'\n';
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
