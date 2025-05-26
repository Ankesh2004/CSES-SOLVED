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
    ll l=0,r=0;
    unordered_map<ll,ll>s;
    ll ans=0;
    for(;r<n;r++){
        if(s.count(v[r]) && s[v[r]]>=l){
            ll len=r-l;
            // cout<<"L:"<<len<<'\n';
            // ans+=((len*(len-1))/2);
            l=s[v[r]]+1;
        }
        ans+=(r-l+1);
        // cout<<l<<" "<<r<<'\n';
        s[v[r]]=r;
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