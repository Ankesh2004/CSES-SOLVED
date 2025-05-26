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
    vector<ll>v(n),p(n,0),s(n,0);
    fri(n){
        cin>>v[i];
    }
    sortv(v);
    fri(n){
        p[i]=v[i];s[i]=v[i];
    }
    fri(n-1){
        p[i+1]+=p[i];
    }
    for(int i=n-2;i>=0;i--){
        s[i]+=s[i+1];
    }
    ll ans=1e16;
    if(n==1){
        cout<<2*v[0]<<'\n';
        return;
    }
    fri(n-1){
        ans=min(ans,2*(max(p[i],s[i+1])));
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