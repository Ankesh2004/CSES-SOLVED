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
    map<ll,ll>s;
    ll ans=1;
    for(;r<n;r++){
        if(s.count(v[r])){
            ll idx=s[v[r]]+1;
            while(l<idx){
                s[v[l]]--;
                if(s[v[l]]==0)s.erase(v[l]);
                l++;
            }
        }
        s[v[r]]=r;
        ans=max(ans,r-l+1);
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
