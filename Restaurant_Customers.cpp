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
    ll n;
    ll s,e;
    cin>>n;
    vector<pair<ll,ll>>v;
    fri(n){
        cin>>s>>e;
        v.emplace_back(e,s);
    }
    sortv(v);
    priority_queue<ll>q;
    ll ans=0;

    for(int i=n-1;i>=0;i--){
        s=v[i].second;
        e=v[i].first;
        while(!q.empty() && q.top()>e){
            q.pop();
        }
        q.push(s);
        ans=max(ans,(ll)q.size());
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
