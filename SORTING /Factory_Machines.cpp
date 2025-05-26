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
    ll t;cin>>t;
    vector<ll>v(n);
    fri(n){
        cin>>v[i];
    }
    sortv(v);
    ll l=1,r=1e18;
    ll ans=1e18;
    while(l<=r){
        ll m=(r-l)/2+l;
        ll sum=0;
        bool poss=false;
        fri(n){
            sum+=(m/v[i]);
            if(sum>=t){
                poss=true;
                break;
            }
        }
        if(poss){
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