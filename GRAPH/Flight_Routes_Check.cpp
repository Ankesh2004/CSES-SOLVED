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
    ll u,v;
    unordered_map<ll,vector<ll>>adj,rev;
    vector<ll>in(n,0),out(n,0);
    DSU dsu(n);
    fri(m){
        cin>>u>>v;
        u--;
        v--;
        dsu.unite(u,v);
        in[v]++;
        out[u]++;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    if(n==1){
        cout<<"YES\n";
        return;
    }
    if(dsu.getNumOfComp()>1){
        cout<<"NO\n";
        set<ll>s;
        fri(n){
            ll p=dsu.find(i);
            if(s.find(p)==s.end()){
                if(s.empty())s.insert(i);
                else{
                    cout<<*(s.begin())+1<<" "<<i+1<<'\n';
                    return;
                }
            }
        }
        return;
    }
    fri(n){
        if(in[i]==0 && out[i]==0){
            cout<<"NO\n";
            if(i==0)cout<<1<<" "<<2<<'\n';
            else cout<<i+1<<" "<<1<<'\n';
            return;
        }
        else if(in[i]==0){
            cout<<"NO\n";
            cout<<adj[i][0]+1<<" "<<i+1<<'\n';
            return;
        }
        else if(out[i]==0){
            cout<<"NO\n";
            cout<<i+1<<" "<<rev[i][0]+1<<'\n';
            return;
        }
    }
    cout<<"YES\n";



}
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}