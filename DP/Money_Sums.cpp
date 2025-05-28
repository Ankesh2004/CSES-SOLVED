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
const ll MAXN = 1e5+6;

 
void solve() {
    ll n;cin>>n;
    vector<ll>v(n);
    ll sum=0;
    fri(n){
        cin>>v[i];
        sum+=v[i];
    }
    vector<int>dp(sum+1,0);
    dp[0]=1;

    for(auto it:v){
        for(int i=sum;i>=1;i--){
            if((i-it)>=0){
                dp[i]=max(dp[i],dp[i-it]);
            }
        }
    }
    vector<ll>ans;
    for(int i=1;i<=sum;i++){
        if(dp[i]==1)ans.push_back(i);
    }
    cout<<ans.size()<<'\n';
    printv(ans,0);cout<<'\n';
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}
