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
    vector<pair<ll,ll>>v(n);
    ll x;
    fri(n){
        cin>>x;
        v[i]={x,i};
    }
    sortv(v);
    multiset<ll>s;

    fri(n){
        ll idx=v[i].second;
        if(s.empty()){
            s.insert(idx);
        }
        else{
            auto it=s.upper_bound(idx);
            if(it!=s.end()){
                s.erase(it);

            }
            s.insert(idx);
        }
    }
    cout<<s.size()<<'\n';

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
