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
    ll n, m;
    cin >>n>>m;
    unordered_map<ll,vector<pair<ll,ll>>>adj;
    ll u,v,de;
    fri(m){
        cin>>u>>v>>de;
        adj[u].push_back({v,de});
    }
    vector<ll>dist(n+1,LLONG_MAX);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    pq.push({0,1});
    dist[1]=0;

    while(!pq.empty()){
        ll d=pq.top().first,x=pq.top().second;
        pq.pop();

        if(d>dist[x])continue;

        for(auto&[it,de]:adj[x]){
            ll nd=d+de;
            if(nd<dist[it]){
                dist[it]=nd;
                pq.push({nd,it});
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
    


}
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}