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

ll mod = 1e9 + 7;
ll MAXN=1e6;
void solve(){
    ll n,m;cin>>n>>m;
    vector<pair<ll,ll>>v(n);
    ll x,y;
    map<ll,ll>idx;
    fri(n){
        cin>>x;
        v[i]={x,i};
    }
    sortv(v);
    vector<ll>b(n),bn(n);
    fri(n){
        idx[v[i].ss]=i;
        b[i]=v[i].ss;
        bn[i]=b[i];
    }
    ll times=1;
    for(int i=1;i<n;i++){
        if(v[i-1].second>v[i].second){
            times++;
        }
    }
    printv(b,0);cout<<'\n';
    fri(m){
        cin>>x>>y;
        x--;y--;
        ll xidx=idx[x],yidx=idx[y];
        ll netchange=0;

        cout<<x<<" "<<y<<" "<<xidx<<" "<<yidx<<'\n';
        swap(bn[xidx],bn[yidx]);
        if(xidx>0){
            if(b[xidx-1]>b[xidx] && bn[xidx-1]<bn[xidx]){
                netchange--;
            }
            if(b[xidx-1]<b[xidx] && bn[xidx-1]>bn[xidx]){
                netchange++;
            }
        }
        if(xidx < n-1){
            if(b[xidx+1] < b[xidx] && bn[xidx+1] >bn[xidx]){
            netchange--;
            }
            if(b[xidx+1] > b[xidx] && b[xidx+1] < bn[xidx]){
            netchange++;
            }
        }
        if(yidx<n-1){
            if(b[yidx+1]<b[yidx] && b[yidx+1]>bn[yidx]){
                netchange--;
            }
            if(b[yidx+1]>b[yidx] && b[yidx+1]<bn[yidx]){
                netchange++;
            }
        }
        if(yidx > 0){
            if(b[yidx-1] > b[yidx] && b[yidx-1] < bn[yidx]){
            netchange--;
            }
            if(b[yidx-1] < b[yidx] && b[yidx-1] > bn[yidx]){
            netchange++;
            }
        }
        idx[x] = yidx;
        idx[y] = xidx;
        swap(b[xidx],b[yidx]);
        bn=b;
        cout<<times+netchange<<'\n';
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
