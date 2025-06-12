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
    ll a,b;cin>>a>>b;
    b++; // fixx
    a--;
    vector<ll>dp(20,0);
    dp[0]=1;
    for(int i=1;i<20;i++){
        dp[i]=(dp[i-1]*9);
    }

    string sa=to_string(a),sb=to_string(b);
    ll na=sa.size(),nb=sb.size();
    ll va=0,vb=0;
    for(int i=1;i<=na-1;i++){
        va+=dp[i];
    }
    for(int i=1;i<=nb-1;i++){
        vb+=dp[i];
    }
    cout<<vb<<'\n';
    ll idx=na-1;
    
    for(int i=0;i<na;i++){
        if(i==0){
            va+=((sa[i]-'0'-1)*dp[idx]);
            cout<<((sa[i]-'0'-1)*dp[idx])<<'\n';
        }
        else if(i==(na-1)){
            if(sa[i]>=sa[i-1]){
                va+=((sa[i]-'0'));
                // cout<<((sa[i]-'0'-1)*dp[idx])<<'\n';
            }
            else{
                va+=((sa[i]-'0'+1)*dp[idx]);
                // cout<<((sa[i]-'0'+1)*dp[idx])<<'\n';
            }
        }
        else{
            if(sa[i]>=sa[i-1]){
                va+=((sa[i]-'0'-1)*dp[idx]);
                cout<<((sa[i]-'0'-1)*dp[idx])<<'\n';
            }
            else{
                va+=((sa[i]-'0')*dp[idx]);
                cout<<((sa[i]-'0')*dp[idx])<<'\n';
            }
        }
        idx--;
    }

    idx=nb-1;
    for(int i=0;i<nb;i++){
        if(i==0){
            vb+=((sb[i]-'0'-1)*dp[idx]);
            cout<<((sb[i]-'0'-1)*dp[idx])<<'\n';
        }
        else if(i==(nb-1)){
            if(sb[i]>=sb[i-1]){
                vb+=((sb[i]-'0'));
                // cout<<((sb[i]-'0'-1)*dp[idx])<<'\n';
            }
            else{
                vb+=((sb[i]-'0'+1)*dp[idx]);
                // cout<<((sb[i]-'0'+1)*dp[idx])<<'\n';
            }
        }
        else{
            if(sb[i]>=sb[i-1]){
                vb+=((sb[i]-'0'-1)*dp[idx]);
                cout<<((sb[i]-'0'-1)*dp[idx])<<'\n';
            }
            else{
                vb+=((sb[i]-'0')*dp[idx]);
                cout<<((sb[i]-'0')*dp[idx])<<'\n';
            }
        }
        idx--;
    }
    cout<<"VV:"<<' '<<va<<" "<<vb<<'\n';

    cout<<(vb-va)<<'\n';

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
