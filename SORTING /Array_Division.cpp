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
    ll k;cin>>k;
    vector<ll>v(n);
    fri(n)cin>>v[i];
    ll l = *max_element(v.begin(), v.end()); 
    ll r = accumulate(v.begin(), v.end(), 0LL);
    ll ans = r;
    while(l<=r){
        ll m=(r-l)/2+l;
        ll curr=0,tot=1;
        bool poss=true;
        fri(n){
            if(v[i]>m){
                poss=false;
                break;
            }
            curr+=v[i];
            if(curr>m){
                curr=v[i];
                tot++;
            }
        }
        if(poss && tot<=k){
            ans=m;
            r=m-1;
        }
        else{
            l=m+1;
        }
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