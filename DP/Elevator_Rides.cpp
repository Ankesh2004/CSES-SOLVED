#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define lld long double
#define pb push_back
#define ff first
#define ss second
#define fri(n) for (int i = 0; i < n; i++)
#define sortv(v) sort((v).begin(), (v).end())
#define printv(v, start_idx)                   \
    for (int i = start_idx; i < v.size(); i++) \
        cout << v[i] << " ";

const ll mod = 1e9 + 7;
const ll MAXN = 1e5 + 6;


void solve()
{
    ll n,w;
    cin>>n>>w;
    vector<ll>v(n);
    fri(n)cin>>v[i];

    vector<pair<ll,ll>>dp((1<<n),{1e10,1e10});

    dp[0]={1,0};

    for(ll mask=1;mask<(1<<n);mask++){
        for(ll i=0;i<n;i++){
            if((1<<i)&mask){
                ll lastone=(mask)^(1<<i);
                ll occupied=dp[lastone].second;
                if((occupied+v[i])<=w){
                    dp[mask]=min(dp[mask],{dp[lastone].first,occupied+v[i]});
                }
                else{
                    dp[mask]=min(dp[mask],{dp[lastone].first+1,v[i]});
                }
            }
        }
    }
    ll minrides=dp[(1<<n)-1].first;
    cout<<minrides<<'\n';

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
