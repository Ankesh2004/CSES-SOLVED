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
    ll n,m,u,v,cost;
    cin>>n>>m;

    unordered_map<ll,vector<pair<ll,ll>>>adj;
    fri(m){
        cin>>u>>v>>cost;
        adj[u].push_back({v,cost});
    }

    vector<ll> dist(n+1, 1e18);
    vector<ll> ways(n+1, 0);
    vector<ll> minFlights(n+1, 1e18);
    vector<ll> maxFlights(n+1, 0);
    
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    ways[1] = 1;
    minFlights[1] = 0;
    maxFlights[1] = 0;
    
    while(!pq.empty()){
        ll d= pq.top().ff;
        ll u= pq.top().ss;
        pq.pop();
        
        if(d > dist[u]) continue;
        
        for(auto edge : adj[u]){
            ll v = edge.ff;
            ll w = edge.ss;
            
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                ways[v] = ways[u];
                minFlights[v] = minFlights[u] + 1;
                maxFlights[v] = maxFlights[u] + 1;
                pq.push({dist[v], v});
            }
            else if(dist[u] + w == dist[v]){
                ways[v] = (ways[v] + ways[u]) % mod;
                minFlights[v] = min(minFlights[v], minFlights[u] + 1);
                maxFlights[v] = max(maxFlights[v], maxFlights[u] + 1);
            }
        }
    }
    
    ll a = dist[n];
    ll b = ways[n];
    ll c = minFlights[n];
    ll d = maxFlights[n];
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<'\n';

}
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}