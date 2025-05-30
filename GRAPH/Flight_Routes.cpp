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
    ll n, m,k;
    cin >>n>>m>>k;
    ll u,v,c;
    unordered_map<ll,vector<pair<ll,ll>>>adj;
    fri(m){
        cin>>u>>v>>c;
        u--;v--;
        adj[u].push_back({v,c});
    }
    vector<ll>visited(n,0);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>>pq;
    pq.push({0,0});// dist,node
    vector<ll>ans;
    while(!pq.empty() && ans.size()<k){
        ll d=pq.top().first,node=pq.top().second;
        pq.pop();

        if(visited[node]>=k)continue;
        visited[node]++;

        if(node==n-1){
            ans.pb(d);
        }
        for(auto it:adj[node]){
            pq.push({d+it.ss,it.ff});
        }
    }
    printv(ans,0);


}
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}