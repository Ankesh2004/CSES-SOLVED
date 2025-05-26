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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll>v1(n),v2(m);
    fri(n)cin>>v1[i];
    fri(m)cin>>v2[i];
    sortv(v1);
    sortv(v2);

    ll p1=0,p2=0;
    ll ans=0;
    while(p1<n && p2<m){
        if(v1[p1]<(v2[p2]-k)){
            p1++;
        }
        else if(v1[p1]>(v2[p2]+k)){
            p2++;
        }
        else{
            ans++;
            p1++;p2++;
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
