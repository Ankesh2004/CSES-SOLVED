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

    const int m = 20;
    const int total = 1 << m; // 2^20
    ll ans=0;
    for (int mask = 0; mask < total; ++mask) {
        bitset<20> b(mask);
        ll sum=0;
        for(int idx = 0; idx < 20; idx++){
            if(b[idx]){
                sum+=v[idx];
            }
        }
        if(sum<=w){
            ans=max(ans,sum);
        }
    }
    cout<<ans<<'\n';

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
