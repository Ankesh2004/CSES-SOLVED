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
    ll val=n*(n+1);
    if((val%4)!=0){
        cout<<0<<'\n';
        return;
    }
    val/=4;
    vector<ll>dp(val+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=val;j>=i;j--){
            dp[j]=(dp[j]+dp[j-i])%mod;
        }
    }
    ll inv2 = 500000004; // modular inverse of 2 modulo 10^9+7
    cout<<(dp[val]*inv2)%mod<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
