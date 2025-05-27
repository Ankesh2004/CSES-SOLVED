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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
ll mod = 1e9 + 7;
ll MAXN=1e6;
void solve(){
    ll n;cin>>n;

    ordered_set<ll>s;
    fri(n)s.insert(i+1);

    ll curr=1;
    fri(n){
        if(curr>=s.size()){
            curr%=(s.size());
        }
        ll val=*s.find_by_order(curr);
        s.erase(val);
        curr++;
        cout<<val<<' ';
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