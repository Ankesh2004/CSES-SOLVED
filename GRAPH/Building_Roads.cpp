#include <bits/stdc++.h>
using namespace std;
 
class DisjointSet
{
    vector<int> parent, rank, size;
 
public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
 
    int findUPar(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = findUPar(parent[x]);
        }
        return parent[x];
    }
 
    void unionByRank(int x, int y)
    {
        int ulp_x = findUPar(x);
        int ulp_y = findUPar(y);
        if (ulp_x == ulp_y)
            return;
        if (rank[ulp_x] < rank[ulp_y])
        {
            parent[ulp_x] = ulp_y;
        }
        else if (rank[ulp_x] > rank[ulp_y])
        {
            parent[ulp_y] = ulp_x;
        }
        else
        {
            parent[ulp_y] = ulp_x;
            rank[ulp_x]++;
        }
    }
    void unionBySize(int x, int y)
    {
        int ulp_x = findUPar(x);
        int ulp_y = findUPar(y);
        if (ulp_x == ulp_y)
            return;
        if (size[ulp_x] < size[ulp_y])
        {
            parent[ulp_x] = ulp_y;
            size[ulp_y] += size[ulp_x];
        }
        else
        {
            parent[ulp_y] = ulp_x;
            size[ulp_x] += size[ulp_y];
        }
    }
    int countSets()
    {
        int count=0;
        for(int i=0;i<parent.size();i++){
            if(i==parent[i]){
                count++;
            }
        }
        return count;
    }
};
 
int main()
{
    int n,m;
    cin>>n>>m;
 
    DisjointSet ds(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        ds.unionByRank(x,y);
    }
    set<int>ulp;
    for(int i=1;i<=n;i++){
        ulp.insert(ds.findUPar(i));
    }
    vector<int>vulp;
    for(auto it:ulp)vulp.push_back(it);
 
    int roads=ds.countSets()-2;
 
    cout<<roads<<endl; 
    if(roads>0){
        for(int i=1;i<vulp.size();i++){
        cout<<vulp[i-1]<<" "<<vulp[i]<<endl;
    }
    }
    
 
    return 0;
}