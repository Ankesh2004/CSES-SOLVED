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

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};


class DSU {
    public:
    vector<ll>par,rank,size;
    ll components,largest;
    DSU(ll n){
        par.resize(n);
        rank.resize(n,0);
        size.resize(n,1);
        components=n;
        largest=1;
        fri(n){
            par[i]=i;
        }
    }
    ll find(ll x){
        if(par[x]!=x){
            return par[x]=find(par[x]);
        }
        return par[x];
    }
    bool unite(ll x,ll y){
        ll px=find(x),py=find(y);
        if(px==py)return false;
        if(rank[px]<rank[py]){
            par[px]=py;
            size[py]+=size[px];
            largest=max(largest,size[py]);
        }
        else if(rank[px]>rank[py]){
            par[py]=px;
            size[px]+=size[py];
            largest=max(largest,size[px]);
        }
        else{
            par[py]=px;
            rank[px]++;
            size[px]+=size[py];
            largest=max(largest,size[px]);
        }
        components--;
        return true;
    }
    bool connected(ll x,ll y){
        return find(x)==find(y);
    }
    ll getNumOfComp(){
        return components;
    }
    ll getmaxsz(){
        return largest;
    }
};
void solve()
{
    ll n,m;
    cin >>n>>m;
    ll u,v,c;
    DSU dsu(n);

    vector<pair<ll,pair<ll,ll>>>edges;

    fri(m){
        cin>>u>>v>>c;
        u--;
        v--;
        edges.push_back({c,{u,v}});
    }
    sort(edges.begin(),edges.end());
    ll edgecnt=0;
    ll idx=0,totcost=0;
    
    for(auto it:edges){
        if(dsu.unite(it.second.first,it.second.second)){
            edgecnt++;
            totcost+=it.first;
        }    
        if(edgecnt==n-1){
            break;
        }
    }
    if(edgecnt==n-1){
        cout<<totcost<<'\n';
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }


}
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}