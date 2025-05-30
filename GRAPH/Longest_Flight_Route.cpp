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

ll dfs(ll node, ll&target,unordered_map<ll,vector<ll>>&adj,vector<ll>&maxdist,vector<ll>&par){
    if(node==target)return 0;
    if(maxdist[node]!=-1e10)return maxdist[node];
    ll maxpath=-1e10;
    ll nextnode=-1;
    for(auto it:adj[node]){
        ll len=1+dfs(it,target,adj,maxdist,par);
        if(len>maxpath){
            nextnode=it;
            maxpath=len;
        }
    }
    if(nextnode!=-1)
        par[node]=nextnode;
        
    return maxdist[node]=maxpath;
}
 
void solve()
{
    ll n, m;
    cin >>n>>m;
    ll u,v;
    unordered_map<ll,vector<ll>>adj;
    fri(m){
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
    }
    ll target=n-1;
    vector<ll>maxdist(n,-1e10),par(n,-1);
    ll len=dfs(0,target,adj,maxdist,par);
    if(len==-1e10){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    u=0;
    vector<ll>order;
    while(u!=-1 && u<n){
        order.pb(u+1);
        if(u==target)break;
        u=par[u];
    }
    ll p=order.size();
    if(order[p-1]!=n){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    
    cout << order.size() << '\n';
    printv(order, 0);
    cout << '\n';

}
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}