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
    ll n,k;
    cin>>n>>k;

    vector<pair<ll,ll>>v(n);
    ll x;
    fri(n){
        cin>>x;
        v[i]={x,i};
    }
    sortv(v);
    map<ll,ll>mp;

    fri(n){
        ll p=k-v[i].first;
        if(mp.count(p)!=0){
            cout<<mp[p]+1<<" "<<v[i].second+1<<'\n';
           return;
        }
        mp[v[i].first]=v[i].second;
    }
    cout<<"IMPOSSIBLE"<<'\n';


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
