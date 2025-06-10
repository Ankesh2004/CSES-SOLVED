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


// void solve()
// {
//     ll n;
//     cin>>n;
//     vector<pair<pair<ll,ll>,ll>>v(n); // start,end,price
//     fri(n){
//         cin>>v[i].ff.ff>>v[i].ff.ss>>v[i].ss;
//     }
//     multiset<pair<ll,ll>>ms;

//     // {start,idx}
//     sortv(v);

//     // {end,idx}
//     vector<pair<ll,ll>>v2;
//     for(int i=0;i<n;i++){
//         v2.push_back({v[i].ff.ss,i});
//     }
//     sort(v2.rbegin(),v2.rend());

//     vector<ll>dp(n,0);

//     for(int i=0;i<n;i++){
//         ll idx=v2[i].second;
        
//         if(ms.empty()){
//             dp[idx]=v[idx].second;
//         }
//         else{
//             auto up=ms.upper_bound({v2[i].first+1,-1});
//             if(up==ms.end()){
//                 dp[idx]=max(dp[idx],v[idx].second);
//             }
//             else{
//                 ll idx2=up->second;
//                 // cout<<"HOLA "<<idx2<<' '<<v2[i].first<<'\n';
//                 dp[idx]=max(dp[idx],v[idx].second+dp[idx2]);
//             }
//         }
//         // cout<<v[idx].ff.ff<<" "<<idx<<'\n';
//         ms.insert({v[idx].first.first,idx});
//     }
//     ll ans=0;
//     for(int i=0;i<n;i++){
//         // cout<<dp[i]<<' ';
//         ans=max(ans,dp[i]);
//     }
//     cout<<ans<<'\n';

// }

void solve()
{
    ll n;
    cin>>n;
    vector<pair<pair<ll,ll>,ll>>v(n); // end,start,price
    fri(n){
        cin>>v[i].ff.ss>>v[i].ff.ff>>v[i].ss;
    }

    sortv(v);
    vector<ll>et;

    for(auto it:v){
        et.push_back(it.ff.first);
    }
    vector<ll>dp(n,0);
    for(int i=0;i<n;i++){
        ll s=v[i].ff.ss;
        ll e=v[i].ff.ff;
        ll p=v[i].ss;

        if(i>0){
            dp[i]=max(dp[i],dp[i-1]);
        }

        ll j = upper_bound(et.begin(), et.begin() + i, s - 1) - et.begin() - 1;
        
        ll take=p;
        if(j>=0)take+=dp[j];

        ll nottake=(i>0)?dp[i-1]:0;

        dp[i]=max({dp[i],take,nottake});
    }

    cout<<dp[n-1]<<'\n';
    

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
