#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define ff first
#define ss second
#define fri(n) for (int i = 0; i < n; i++)
 
void solve() {
    ll n; cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    fri(n) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    vector<pair<ll, ll>> curr;
    curr.push_back({0, 0});
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[0][0] = true;

    string ans = "";
    ans += v[0][0];

    while (!curr.empty()) {
        vector<pair<char, pair<ll, ll>>> next_cells;

        for (auto [x, y] : curr) {
            if ((x + 1) < n && !visited[x + 1][y]) {
                next_cells.push_back({v[x + 1][y], {x + 1, y}});
                visited[x + 1][y] = true;
            }
            if ((y + 1) < n && !visited[x][y + 1]) {
                next_cells.push_back({v[x][y + 1], {x, y + 1}});
                visited[x][y + 1] = true;
            }
        }

        if (!next_cells.empty()) {
            sort(next_cells.begin(), next_cells.end());
            
            char nextc = next_cells[0].first;
            ans += nextc;
            
            curr.clear();
            for (auto& cell : next_cells) {
                if (cell.first == nextc) {
                    curr.push_back(cell.second);
                }
                else break;
            }
        } 
        else break;
    }

    cout << ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}