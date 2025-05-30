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
const ll MAXN = 1e5 + 6;

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};

 
void solve()
{
    ll n,m;cin>>n>>m;
    ll u,v,c;
    vector<vector<ll>>edges(m,vector<ll>(3));
    fri(m){
        cin>>u>>v>>c;
        u--;v--;
        edges[i]={u,v,c};
    }
    vector<ll>dist(n,0);
    vector<ll>par(n,-1);

    fri(n-1){
        for(auto it:edges){
            if((dist[it[0]]+it[2])<dist[it[1]]){
                dist[it[1]]=dist[it[0]]+it[2];
                par[it[1]]=it[0];
            }
        }
    }
    ll cycle_node=-1;
    for(auto it:edges){
        if( dist[it[0]]+it[2]<dist[it[1]] && (dist[it[0]]+it[2])<0){
            cycle_node=it[1];
            break;
        }
    }
    // cout<<cycle_node<<'\n';
    if(cycle_node == -1) {
        cout << "NO\n";
        return;
    }
    fri(n) {
        cycle_node = par[cycle_node];
    }
    cout<<"YES\n";
    vector<ll>cycle;
    // printv(par,0);cout<<'\n';
    ll curr=cycle_node;
    do {
        cycle.pb(curr + 1);
        curr = par[curr];
    } while(curr != cycle_node);
    
    cycle.pb(cycle_node + 1);
    
    for(ll node : cycle) {
        cout << node << " ";
    }
    cout << "\n";


}
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}