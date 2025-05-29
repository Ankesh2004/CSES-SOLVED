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

ll f(unordered_map<ll,vector<ll>>&adj,ll n,ll src){
    vector<ll>prev(n+1,-1);
    stack<ll>q;
    ll u;
    q.push(src);
    ll start=-1;
    while(!q.empty()){
        ll x=q.top();
        q.pop();
        if(start!=-1)break;
        for(auto it:adj[x]){
            if(prev[it]!=-1){
                start=it;
            }
            prev[it]=x;
            q.push(it);
        }
    }
    if(start==-1){
        return -1;
    }
    u=prev[start];
    vector<ll>ans;
    ans.push_back(u);
    while(u!=start){
        ans.push_back(u);
        u=prev[u];
    }
    printv(ans,0);cout<<'\n';
    return 1;
}
 
void solve()
{
    ll n, m,queries;
    cin >>n>>m>>queries;
    unordered_map<ll,vector<ll>>adj;
    ll u,v;
    fri(m){
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(f)
    }
    
    
}
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}