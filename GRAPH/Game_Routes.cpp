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
    ll n,m,u,v;
    cin>>n>>m;

    unordered_map<ll,vector<ll>>adj;
    vector<ll>ways(n+1,0);ways[1]=1;
    vector<ll>indeg(n+1,0);
    fri(m){
        cin>>u>>v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    queue<ll>q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0)q.push(i);
    }

    while(!q.empty()){
        ll node=q.front();
        q.pop();

        for(auto it:adj[node]){
            indeg[it]--;
            ways[it]=(ways[node]+ways[it])%mod;
            if(indeg[it]==0)q.push(it);
        }
    }
    // printv(ways,0);cout<<'\n';
    cout<<ways[n]<<'\n';

}
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}