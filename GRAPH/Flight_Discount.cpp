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
    ll n,m;
    cin >>n>>m;
    ll u,v,c;
    unordered_map<ll,vector<pair<ll,ll>>>adj;
    fri(m){
        cin>>u>>v>>c;
        u--;v--;
        adj[u].push_back({v,c});
    }
    vector<vector<ll>>vis(n,vector<ll>(2,0));
    priority_queue<pair<pair<ll,ll>,ll>,vector<pair<pair<ll,ll>,ll>>,greater<>>pq;
    pq.push({{0,0},0});// dist,node, halfed?
    ll ans=1e18;
    while(!pq.empty()){
        ll d=pq.top().first.first,node=pq.top().first.second;
        ll halfed=pq.top().second;
         pq.pop();
        //  cout<<node<<" "<<d<<'\n';
        if(vis[node][halfed]==1)continue;
        vis[node][halfed]=1;
        

        if(node==n-1){
            cout<<d<<'\n';
            return;
        }
        for(auto it:adj[node]){
            pq.push({{d+it.ss,it.ff},halfed});
            if(halfed==0){
                pq.push({{d + (it.ss / 2), it.ff}, 1}); 
            }
        }
        
    }
    cout<<ans<<'\n';


}
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}