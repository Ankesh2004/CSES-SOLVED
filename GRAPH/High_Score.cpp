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

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}
 
void solve()
{
    ll n, m;
    cin >>n>>m;
    vector<vector<ll>>adj(m,vector<ll>(3));
    vector<ll>dist(n+1,-1e18);
    vector<vector<int>> graph(n+1), reverse_graph(n+1);
    
    ll u,v,de;
    fri(m){
        cin>>u>>v>>de;
        adj[i]={u,v,de};
        graph[u].push_back(v);
        reverse_graph[v].push_back(u);
    }
    dist[1]=0;

    for(int i=0;i<n-1;i++){
        for(auto it:adj){
            ll u=it[0],v=it[1],d=it[2];
            if(dist[u]!=-1e18 && (dist[u]+d)>dist[v]){
                dist[v]=dist[u]+d;
            }
        }
    }
    
    vector<bool> reachable_from_1(n+1, false);
    dfs(1, graph, reachable_from_1);
    
    vector<bool> can_reach_n(n+1, false);
    dfs(n, reverse_graph, can_reach_n);
    
    for(auto it:adj){
        ll u=it[0],v=it[1],d=it[2];
        if(dist[u]!=-1e18 && (dist[u]+d)>dist[v]){

            if(reachable_from_1[u] && can_reach_n[v]){
                cout<<-1<<'\n';
                return;
            }
        }
    }
    
    cout<<dist[n]<<'\n';
}
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}