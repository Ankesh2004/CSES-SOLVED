#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define fri(n) for (int i = 0; i < n; i++)
#define sortv(v) sort((v).begin(), (v).end())
#define printv(v, start_idx)                   \
    for (int i = start_idx; i < v.size(); i++) \
        cout << v[i] << " ";

ll mod = 1e9 + 7;
ll MAXN=2e5+5;
ll LOGN = 30;

vector<vector<ll>>up(MAXN,vector<ll>(LOGN));

void precomp(ll n){
    for(int i=1;i<=LOGN;i++){
        for(int j=1;j<=n;j++){
            up[j][i]=up[up[j][i-1]][i-1];
        }
    }
}
ll query(ll u,ll k){
    ll x=u;
    for(int i=0;i<=30;i++){
        if(k&(1<<i)){
            x=up[x][i];
        }
    }
    return x;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    for(int i=2;i<=n;i++){
        cin>>up[i][0];
    }
    precomp(n);
    ll u,k;
    for(int i=1;i<=m;i++){
        cin>>u>>k;
        ll ans=query(u,k);
        ans=(ans==0)?-1:ans;
        cout<<ans<<'\n';
    }
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ll t;
    // cin >> t;
    // fri(t)
        solve();

    return 0;
}
