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
    cin>>n;
    vector<ll>v(n),p(n);
    map<ll,ll>mp;
    k=n;
    fri(n){
        cin>>v[i];
        v[i]%=n;
    }
    mp[0]=1;
    ll ans=0,sum=0;

    fri(n){
        sum+=v[i];
        sum=(sum+n)%n;
        if(mp.count(sum))ans+=mp[sum];
        mp[sum]++;
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}
