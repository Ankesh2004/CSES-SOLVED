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
    ll n;
    cin>>n;
    vector<pair<pair<ll,ll>,ll>>v;
    ll l,r;
    fri(n){
        cin>>l>>r;
        v.pb({{l,r},i});
    }
    sortv(v);
    set<ll>rooms;
    deque<ll>free;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>>pq; // endtime, room no.
    vector<ll>occupied(n,-1);
    ll total=1;
    for(int i=0;i<n;i++){
        ll s=v[i].ff.ff,e=v[i].ff.ss,idx=v[i].ss;
 
        while(!pq.empty() && s>pq.top().ff){
            free.push_back(pq.top().ss);
            rooms.erase(pq.top().ss);
            pq.pop();
        }
        ll r;
        if(free.empty()){
            r=rooms.size()+1;
            rooms.insert(r);
            occupied[idx]=r;
        }
        else{
            r=free.front();
            free.pop_front();
            rooms.insert(r);
            occupied[idx]=r;
        }
        pq.push({e,r});
        total=max(total,(ll)rooms.size());
    }
    cout<<total<<'\n';
    for(auto it:occupied)cout<<it<<" ";
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}
