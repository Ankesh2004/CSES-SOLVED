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
const ll MAXN = 1002;
 
 
void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll>v(n);
    fri(n)cin>>v[i];
    ll ans=n;

    map<ll,ll>s;
    ll l=0,r=0;
    while(l <= r && r < n){
        ll sz=s.size();
        if((sz < k) || (sz==k && s.find(v[r]) != s.end())){
            s[v[r]]++;
            ll len=r-l+1;
            ans+=(len-1);
            r++;
        }
        else{
                s[v[l]]--;
                if(s[v[l]]==0)s.erase(v[l]);
                l++;
        }
        
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}
