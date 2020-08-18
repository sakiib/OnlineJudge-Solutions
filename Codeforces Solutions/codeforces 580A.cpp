#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &V)
{
    int ans=1,mx=1;
    for(int i=0;i<V.size()-1;i++){
        if(V[i+1]>=V[i]) ans++;
        else {
            mx=max(ans,mx);
            ans=1;
        }
    }
    mx=max(ans,mx);
    return mx;
}
int main()
{
    vector<int> V;
    int n,num;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num;
        V.push_back(num);
    }
    cout<<solve(V);
    return 0;
}
