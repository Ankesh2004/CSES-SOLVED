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
 
ll mod = 1e9 + 7;
const ll MAXN = 1002;
 
 
void solve() {
    ll n,k;
    cin>>n>>k;
    map<ll,ll>mp;
    ll x;
    vector<pair<ll,ll>>v;
    fri(n){
        cin>>x;
        v.pb({x,i});
    }
    sortv(v);
    mp[v[0].ff]=v[0].ss;
    for(int i=1;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            ll val=k-v[i].first-v[j].first;
            if(mp.count(val)){
                cout<<mp[val]+1<<" "<<v[i].second+1<<" "<<v[j].ss+1<<'\n';
                return;
            }
        }
        mp[v[i].ff]=v[i].ss;
    }
    cout<<"IMPOSSIBLE\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}
