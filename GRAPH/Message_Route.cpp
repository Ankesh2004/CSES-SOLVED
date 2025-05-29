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
    unordered_map<ll,vector<ll>>adj;
    ll u,v;
    fri(m){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll>prev(n+1,-1);
    queue<ll>q;
    q.push(1);

    while(!q.empty()){
        ll x=q.front();
        q.pop();

        if(x==n){
            break;
        }

        for(auto it:adj[x]){
            if(prev[it]==-1){
                prev[it]=x;
                q.push(it);
            }
        }
    }
    if(prev[n]==-1){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        u=n;
        vector<ll>ans;
        ans.push_back(n);
        while(u!=1){
            u=prev[u];
            ans.push_back(u);
        }
        ll sz=ans.size();
        cout<<sz<<"\n";
        for(int i=sz-1;i>=0;i--){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
    }
    


}
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}