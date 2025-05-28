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
    ll n;
    cin >> n;
    vector<ll>v(n);
    fri(n){
        cin>>v[i];
    }
    vector<ll>ans;
    fri(n){
        ll sz=ans.size();
        if(sz==0 || ans[sz-1]<v[i]){
            ans.pb(v[i]);
        }
        else{
            ll idx=lower_bound(ans.begin(),ans.end(),v[i])-ans.begin();
            ans[idx]=v[i];
        }
    }
    ll a=ans.size();
    cout<<a<<'\n';

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
