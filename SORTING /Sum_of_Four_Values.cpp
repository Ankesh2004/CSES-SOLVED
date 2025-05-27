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
    map<ll,pair<ll,ll>>mp;
    ll x;
    vector<pair<ll,ll>>v;
    fri(n){
        cin>>x;
        v.pb({x,i});
    }
    if(n<=3){
        cout<<"IMPOSSIBLE\n";
        return;  
    }
    sortv(v);
    mp[v[0].ff+v[1].ff]={v[0].ss,v[1].ss};
    for(int i=2;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            ll val=k-v[i].first-v[j].first;
            if(mp.count(val)){
                cout<<mp[val].ff+1<<" "<<mp[val].ss+1<<" "<<v[i].second+1<<" "<<v[j].ss+1<<'\n';
                return;
            }
        }
        for(int j=0;j<i;j++){
            mp[v[i].ff+v[j].ff]={v[i].ss,v[j].ss};
        }
    }
    cout<<"IMPOSSIBLE\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}
