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
    ll n, m;
    cin >> n >> m;
    vector<ll> v1(n), v2(m);
    fri(n) cin >> v1[i];
    for (int i = 0; i < m; i++) cin >> v2[i];

    vector<vector<pair<ll, ll>>> dp(n + 1, vector<pair<ll, ll>>(m + 1, {0, 0}));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v1[i - 1] == v2[j - 1]) {
                dp[i][j].ff = dp[i - 1][j - 1].ff + 1;
                dp[i][j].ss = 3; // from diagonal (match)
            } else if (dp[i - 1][j].ff >= dp[i][j - 1].ff) {
                dp[i][j].ff = dp[i - 1][j].ff;
                dp[i][j].ss = 2; // from above
            } else {
                dp[i][j].ff = dp[i][j - 1].ff;
                dp[i][j].ss = 1; // from left
            }
        }
    }

    vector<ll> ans;
    ll x = n, y = m;
    while (x > 0 && y > 0) {
        if (dp[x][y].ss == 3) {
            ans.push_back(v1[x - 1]);
            x--; y--;
        } else if (dp[x][y].ss == 2) {
            x--;
        } else {
            y--;
        }
    }

    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<'\n';
    printv(ans, 0);
    cout << '\n';
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
