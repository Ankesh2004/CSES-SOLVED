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
    ll n,m;
    cin>>n>>m;
    multiset<ll>s;
    ll x;
    fri(n){
        cin>>x;
        s.insert(x);
    }
    fri(m){
        cin>>x;
        auto it=s.upper_bound(x);
        if(it==s.begin()){
            cout<<-1<<'\n';
        }
        else{
            cout<<*(--it)<<"\n";
            s.erase(it);
        }
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
