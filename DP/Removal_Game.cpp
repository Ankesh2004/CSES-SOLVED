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

ll f(vector<vector<ll>> &dp, int i, int j, vector<ll> &v)
{
    if (i > j)
    {
        return -1e18;
    }
    if (dp[i][j] != -1e16)
    {
        return dp[i][j];
    }
    return dp[i][j] = max({dp[i][j], v[i] + f(dp, i + 1, j, v), v[j] + f(dp, i, j - 1, v)});
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    fri(n) cin >> v[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1e16));

    ll ans = f(dp, 0, n - 1, v);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
