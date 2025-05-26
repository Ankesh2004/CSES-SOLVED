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
    sortv(v);
    ll l=0,r=n-1,ans=0;
    while(l<=r){
        if(l==r){
            ans++;
            break;
        }
        if((v[l]+v[r])>k){
            ans++;
            r--;
        }
        else{
            ans++;
            l++;
            r--;
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
