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
ll MAXN=1e6;
void solve(){
    ll n;cin>>n;
    vector<ll>v(n);
    fri(n){
        cin>>v[i];
    }
    ll curr=0,minn=0;
    ll ans=-1e15;
    fri(n){
        curr+=v[i];
        ans=max({ans,curr,curr-minn});
        minn=min(minn,curr);
    }
    cout<<ans<<'\n';
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
