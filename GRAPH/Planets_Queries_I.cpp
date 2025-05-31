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
const ll MAXN = 2e5 + 6;
const ll LOGN = 30;
ll up[MAXN][LOGN];

void preprocess(ll n) {
    for (int j = 1; j < LOGN; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
}
ll query(ll x,ll k){
    for(int j=0;j<LOGN;j++){
        if(k & (1<<j)){
            x=up[x][j];
        }
    }
    return x;
}

void solve()
{
    ll n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        cin>>up[i][0];
    }
    preprocess(n);
    ll x,k;
    fri(q){
        cin>>x>>k;
        cout<<query(x,k)<<'\n';
    }

}
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}