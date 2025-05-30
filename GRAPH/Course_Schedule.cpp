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
    vector<ll>indeg(n,0);
    unordered_map<ll,vector<ll>>adj;
    ll u,v;
    fri(m){
        cin>>u>>v;
        u--;v--;
        indeg[v]++;
        adj[u].push_back(v);
    }
    queue<ll>q;
    fri(n){
        if(indeg[i]==0)q.push(i);
    }
    vector<ll>ans;
    while(!q.empty()){
        ll x=q.front();
        q.pop();
        ans.push_back(x+1);

        for(auto it:adj[x]){
            indeg[it]--;
            if(indeg[it]==0)q.push(it);
        }
        
    }
    if(ans.size()!=n){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    printv(ans,0);cout<<'\n';
}
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}