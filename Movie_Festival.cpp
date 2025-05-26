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

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>>q;
    vector<ll>dp(n,1);
    ll ans=1;
    fri(n){
        if(i>0)dp[i]=max(dp[i],dp[i-1]);
        s=v[i].ss;
        e=v[i].ff;
        while(!q.empty() && s>=q.top().ff){
            dp[i]=max(dp[i],dp[q.top().ss]+1);
            q.pop();
        }
        q.push({e,i});
    }
    cout<<dp[n-1]<<'\n';

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
